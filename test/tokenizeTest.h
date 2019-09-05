#include "../src/tokenize.h"

using namespace tdd;

auto tokenizeTest () -> void {
    describe("tokenize::isVar", [](){
        it("returns false when input is empty string", [](){
            auto actual = tokenize::isVar("");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns false when input starts with uppercase", [](){
            auto expetced = false;

            auto actual = tokenize::isVar("A");
            isEqual(actual, expetced);

            actual = tokenize::isVar("Aa");
            isEqual(actual, expetced);
        });

        it("returns false when input starts with digit", [](){
            auto expetced = false;

            auto actual = tokenize::isVar("1");
            isEqual(actual, expetced);

            actual = tokenize::isVar("1a");
            isEqual(actual, expetced);
        });

        it("returns false when input contains whitespace", [](){
            auto expetced = false;

            auto actual = tokenize::isVar(" a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("a ");
            isEqual(actual, expetced);
        });

        it("returns false when input starts with '(' or ')'", [](){
            auto expetced = false;

            auto actual = tokenize::isVar("(");
            isEqual(actual, expetced);

            actual = tokenize::isVar("(a");
            isEqual(actual, expetced);

            actual = tokenize::isVar(")a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("(a");
            isEqual(actual, expetced);
        });

        it("returns false when input starts with '[' or ']'", [](){
            auto expetced = false;

            auto actual = tokenize::isVar("[");
            isEqual(actual, expetced);

            actual = tokenize::isVar("[a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("]a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("a]");
            isEqual(actual, expetced);
        });

        it("returns false when input starts with '{' or '}'", [](){
            auto expetced = false;

            auto actual = tokenize::isVar("{");
            isEqual(actual, expetced);

            actual = tokenize::isVar("{a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("}a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("a}");
            isEqual(actual, expetced);
        });

        it("returns true when input contains of a-z", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("abc");
            isEqual(actual, expetced);
        });

        it("returns true when input includes '?'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("?abc");
            isEqual(actual, expetced);

            actual = tokenize::isVar("abc?");
            isEqual(actual, expetced);

            actual = tokenize::isVar("??abc?");
            isEqual(actual, expetced);

            actual = tokenize::isVar("??");
            isEqual(actual, expetced);
        });

        it("returns true when input just '?'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("?");
            isEqual(actual, expetced);
        });

        it("returns true when input includes '$'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("$");
            isEqual(actual, expetced);

            actual = tokenize::isVar("$abc");
            isEqual(actual, expetced);

            actual = tokenize::isVar("abc$");
            isEqual(actual, expetced);

            actual = tokenize::isVar("$$abc$");
            isEqual(actual, expetced);

            actual = tokenize::isVar("$$");
            isEqual(actual, expetced);
        });

        it("returns true when input includes '-'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("-a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("-abc");
            isEqual(actual, expetced);

            actual = tokenize::isVar("abc-");
            isEqual(actual, expetced);

            actual = tokenize::isVar("--abc-");
            isEqual(actual, expetced);

            actual = tokenize::isVar("--");
            isEqual(actual, expetced);
        });

        it("returns false when input starts with '-' and digit", [](){
            auto expetced = false;

            auto actual = tokenize::isVar("-0");
            isEqual(actual, expetced);

            actual = tokenize::isVar("-9");
            isEqual(actual, expetced);

            actual = tokenize::isVar("-0.4");
            isEqual(actual, expetced);
        });

        it("returns true when input includes '*'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("*a");
            isEqual(actual, expetced);

            actual = tokenize::isVar("*abc");
            isEqual(actual, expetced);

            actual = tokenize::isVar("abc*");
            isEqual(actual, expetced);

            actual = tokenize::isVar("**abc*");
            isEqual(actual, expetced);

            actual = tokenize::isVar("**");
            isEqual(actual, expetced);

            actual = tokenize::isVar("*9");
            isEqual(actual, expetced);

            actual = tokenize::isVar("-*9");
            isEqual(actual, expetced);
        });

        it("returns true when input is just '*'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("*");
            isEqual(actual, expetced);
        });

        it("returns true when input is '-_-'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("-_-");
            isEqual(actual, expetced);
        });

        it("returns true when input is '<-->'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("<-->");
            isEqual(actual, expetced);
        });

        it("returns true when input is '<|>'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("<|>");
            isEqual(actual, expetced);
        });

        it("returns true when input is '<html>'", [](){
            auto expetced = true;

            auto actual = tokenize::isVar("<html>");
            isEqual(actual, expetced);
        });
    });

    describe("tokenize::isUnresolvedDString", [](){
        it("returns false when input is empty string", [](){
            auto actual = tokenize::isUnresolvedDString("");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns true when input is just quote", [](){
            auto actual = tokenize::isUnresolvedDString("\"");
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns false when input is two quote", [](){
            auto actual = tokenize::isUnresolvedDString("\"\"");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns false when input not includes starting quotes", [](){
            auto actual = tokenize::isUnresolvedDString("no quotes");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns false when input includes starting and ending quotes", [](){
            auto actual = tokenize::isUnresolvedDString("\"no quotes\"");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns true when input ending quote is backslashed", [](){
            auto expetced = true;

            auto actual = tokenize::isUnresolvedDString("\"no quotes\\\"");
            isEqual(actual, expetced);

            actual = tokenize::isUnresolvedDString("\"no quotes\\\\\\\"");
            isEqual(actual, expetced);

            // not backslashed
            actual = tokenize::isUnresolvedDString("\"no quotes\\\\\"");
            isEqual(actual, false);
        });

        it("returns true when input includes starting quotes", [](){
            auto actual = tokenize::isUnresolvedDString("\"no quotes");
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns true when input has newlines", [](){
            auto actual = tokenize::isUnresolvedDString("\"no quotes\n\n");
            auto expetced = true;
            isEqual(actual, expetced);
        });
    });

    describe("tokenize::isResolvedDString", [](){
        it("returns false when input is empty string", [](){
            auto actual = tokenize::isResolvedDString("");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns false when input is just quote", [](){
            auto actual = tokenize::isResolvedDString("\"");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns true when input is two quote", [](){
            auto actual = tokenize::isResolvedDString("\"\"");
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns false when input not includes starting quotes", [](){
            auto actual = tokenize::isResolvedDString("no quotes");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns true when input includes starting and ending quotes", [](){
            auto actual = tokenize::isResolvedDString("\"no quotes\"");
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns true when input ending quote is not backslashed", [](){
            auto expetced = true;

            auto actual = tokenize::isResolvedDString("\"no quotes\\\\\"");
            isEqual(actual, expetced);

            // backslashed
            actual = tokenize::isResolvedDString("\"no quotes\\\"");
            isEqual(actual, false);
        });

        it("returns false when input includes starting quotes", [](){
            auto actual = tokenize::isResolvedDString("\"no quotes");
            auto expetced = false;
            isEqual(actual, expetced);
        });
        it("returns true when input has newlines", [](){
            auto actual = tokenize::isResolvedDString("\"quotes\n\nmultiline\"");
            auto expetced = true;
            isEqual(actual, expetced);
        });
    });

    describe("tokenize::isType", [](){
        it("returns false when input is empty string", [](){
            auto actual = tokenize::isType("");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns false when input includes whitespace", [](){
            auto actual = tokenize::isType(" A");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns true when input is just one uppercase", [](){
            auto expetced = true;

            auto actual = tokenize::isType("A");
            isEqual(actual, expetced);
        });

        it("returns true when input starts with uppercase", [](){
            auto expetced = true;

            auto actual = tokenize::isType("Abc");
            isEqual(actual, expetced);

            actual = tokenize::isType("A_");
            isEqual(actual, expetced);

            actual = tokenize::isType("A1");
            isEqual(actual, expetced);

            actual = tokenize::isType("A_1");
            isEqual(actual, expetced);

            actual = tokenize::isType("A-1");
            isEqual(actual, expetced);
        });
    });

    describe("tokenize::isWhitespace", [](){
        it("returns false when input is empty string", [](){
            auto actual = tokenize::isWhitespace("");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns false when input contains non-whitespace", [](){
            auto actual = tokenize::isWhitespace(" n");
            auto expetced = false;
            isEqual(actual, expetced);
        });

        it("returns true when input contains just whitespace", [](){
            auto expetced = true;

            auto actual = tokenize::isWhitespace("    ");
            isEqual(actual, expetced);

            actual = tokenize::isWhitespace(" \n");
            isEqual(actual, expetced);

            actual = tokenize::isWhitespace(" \n\t");
            isEqual(actual, expetced);
        });
    });


    describe("tokenize::tokenizeInput", [](){
        it("returns empty vector", [](){
            auto actual = tokenize::tokenizeInput("");
            vector<tokenize::Token> expetced = {};
            isEqual(actual, expetced);
        });

        it("returns single token", [](){
            auto input = "xyz.abc?_123*!";
            auto tokens = tokenize::tokenizeInput(input);
            auto actual = tokenize::tokenVectorToStringVector(tokens);

            vector<string> expetced = {
                "xyz.abc?_123*!",
            };

            isEqual(actual, expetced);
        });

        it("returns multiple tokens", [](){
            auto input = "TypeName xyz.abc?_123*!\n    ?isSome";
            auto tokens = tokenize::tokenizeInput(input);
            auto actual = tokenize::tokenVectorToStringVector(tokens);

            vector<string> expetced = {
                "TypeName",
                " ",
                "xyz.abc?_123*!",
                "\n    ",
                "?isSome"
            };

            isEqual(actual, expetced);
        });

        it("can handle double quote strings", [](){
            auto input = "a = \"a string\"";
            auto tokens = tokenize::tokenizeInput(input);
            auto actual = tokenize::tokenVectorToStringVector(tokens);

            vector<string> expetced = {
                "a",
                " ",
                "=",
                " ",
                "\"a string\""
            };

            isEqual(actual, expetced);
        });

        it("can handle double quote strings with backslashed", [](){
            auto input = "a = \"a \\\"string\" ;";
            auto tokens = tokenize::tokenizeInput(input);
            auto actual = tokenize::tokenVectorToStringVector(tokens);

            vector<string> expetced = {
                "a",
                " ",
                "=",
                " ",
                "\"a \\\"string\"",
                " ",
                ";"
            };

            isEqual(actual, expetced);
        });

        it("can handle single quote strings", [](){
            auto input = "a = 'a string'";
            auto tokens = tokenize::tokenizeInput(input);
            auto actual = tokenize::tokenVectorToStringVector(tokens);

            vector<string> expetced = {
                "a",
                " ",
                "=",
                " ",
                "'a string'"
            };

            isEqual(actual, expetced);
        });

        it("can handle comments", [](){
            auto input = "a = 1 # a string #";
            auto tokens = tokenize::tokenizeInput(input);
            auto actual = tokenize::tokenVectorToStringVector(tokens);

            vector<string> expetced = {
                "a",
                " ",
                "=",
                " ",
                "1",
                " ",
                "# a string #"
            };

            isEqual(actual, expetced);
        });
    });
}

#include "../src/tokenize.h"

using namespace tdd;

auto tokenizeTest () -> void {
    describe("tokenize::isVar", [](){
        it("returns false when input is empty string", [](){
            auto actual = tokenize::isVar("A");
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

            auto actual = tokenize::isVar("?");
            isEqual(actual, expetced);

            actual = tokenize::isVar("?abc");
            isEqual(actual, expetced);

            actual = tokenize::isVar("abc?");
            isEqual(actual, expetced);

            actual = tokenize::isVar("??abc?");
            isEqual(actual, expetced);

            actual = tokenize::isVar("??");
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
    });
}

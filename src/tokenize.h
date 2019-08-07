#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>
#include <regex>
#include "./helper.h"

using namespace std;
using namespace helper;

typedef function<bool(string)> TokenCheckFunc;

const vector<string> reservedOperator = {
    "+",
    "-",
    "*",
    "/",
    "?",
    ".",
    "=",
    "->",
    "=>"
};

auto makeIsResolvedWrapper (string symbol) -> TokenCheckFunc {
    return [](string input) {
        return false;
    };
};

auto makeIsUnresolvedWrapper (string symbol) -> TokenCheckFunc {
    return [](string input) {
        return false;
    };
};

namespace tokenize {

    auto isReservedOperator(string str) -> bool {
        return find(
            reservedOperator.begin(),
            reservedOperator.end(),
            str) != reservedOperator.end();
    };

    auto isVar (string input) -> bool {
        if (isReservedOperator(input)) return false;

        regex prefixRex;
        prefixRex = "^([a-z\?$*]+|-[a-zA-Z\?$*-])(.)*";

        regex allRex;
        allRex = "[a-zA-Z0-9\?$*-]+";

        return (regex_match(input, prefixRex) && regex_match(input, allRex));
    };

    auto isType (string input) -> bool {
        regex prefixRex;
        prefixRex = "^([A-Z]){1}(.)*";

        regex allRex;
        allRex = "[a-zA-Z0-9-_]{1,}";

        return (regex_match(input, prefixRex) && regex_match(input, allRex));
    };

    auto isWhitespace (string input) -> bool {
        regex rex;
        rex = "\\s{1,}";

        return regex_match(input, rex);
    };

    auto isResolvedString = makeIsResolvedWrapper("\"");

    auto isUnresolvedString = makeIsUnresolvedWrapper("\"");

    auto isResolvedComment = makeIsResolvedWrapper("#");

    auto isUnresolvedComment = makeIsUnresolvedWrapper("\"");

    vector<TokenCheckFunc> tokenChecker = {
        isVar,
        isType,
        isWhitespace
    };

    struct Token {
        string content;
        int lineNumber;
        int column;
    };

    inline bool operator==(const Token& t1, const Token& t2)
    {
        return (
            t1.content == t2.content
            && t1.lineNumber == t2.lineNumber
            && t1.column == t2.column
        );
    }

    auto _tokenizeInput (vector<Token> tokens, string input) -> vector<Token> {
        if (input == "") {
            return tokens;
        }

        auto inputHead = head(input);
        auto inputTail = tail(input);

        auto tokensHead = head(tokens);

        if (isEmpty(tokens)) {
            Token firstToken;
            firstToken.content = inputHead.value();
            firstToken.lineNumber = 1;
            firstToken.column = 1;

            tokens.push_back(firstToken);
        }

        if (isEmpty(inputTail)) {
            return tokens;
        }

        return _tokenizeInput(tokens, inputTail.value());
    };

    auto tokenizeInput (string input) -> vector<Token> {
        Token a;
        a.content = "";
        a.lineNumber = 1;
        a.column = 1;

        vector<Token> result = { a };
        return result;
    };
}

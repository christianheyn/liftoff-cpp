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

auto lastIsBackslashed (string input) -> bool {
    reverse(input.begin(), input.end());
    auto noLast = input.substr(1, input.length());

    std::smatch match;
    std::regex e ("^(\\\\){1,}");

    regex_search(noLast,match,e);

    auto backshlashLength = match.length();

    return ((backshlashLength % 2) == 1);
};

auto makeIsResolvedWrapper (char symbol) -> TokenCheckFunc {
    return [symbol](string input) {
        auto inputLength = input.length();

        return (
            inputLength >= 2
            && input.at(0) == symbol
            && input.at(inputLength - 1) == symbol
            && !lastIsBackslashed(input)
        );
    };
};

auto makeIsUnresolvedWrapper (char symbol) -> TokenCheckFunc {
    return [symbol](string input) {
        auto inputLength = input.length();

        return (
            inputLength >= 1
            && input.at(0) == symbol
            && (
                (input.at(inputLength - 1) == symbol && lastIsBackslashed(input))
                || (inputLength > 1 && input.at(inputLength - 1) != symbol)
                || (inputLength == 1)
            )
        );
    };
};

namespace tokenize {
    auto isVar (string input) -> bool {
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

    auto isResolvedDString = makeIsResolvedWrapper('"');
    auto isUnresolvedDString = makeIsUnresolvedWrapper('"');
    auto isResolvedSString = makeIsResolvedWrapper('\'');
    auto isUnresolvedSString = makeIsUnresolvedWrapper('\'');

    auto isResolvedComment = makeIsResolvedWrapper('#');
    auto isUnresolvedComment = makeIsUnresolvedWrapper('#');

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

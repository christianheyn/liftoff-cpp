#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <optional>
#include <regex>
#include <iostream>
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
            && (!makeIsResolvedWrapper(symbol)(input))
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
        isWhitespace,
        isResolvedDString,
        isUnresolvedDString,
        isResolvedSString,
        isUnresolvedSString,
        isResolvedComment,
        isUnresolvedComment
    };

    auto isValidToken = [](string input) -> bool {
        return (
            isVar(input)
            || isType(input)
            || isWhitespace(input)
            || isResolvedDString(input)
            || isUnresolvedDString(input)
            || isResolvedSString(input)
            || isUnresolvedSString(input)
            || isResolvedComment(input)
            || isUnresolvedComment(input)
        );
    };

    struct Token {
        string content;
        int lineNumber;
        int column;
    };

    inline bool operator==(const Token& t1, const Token& t2) {
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

        if (input == "") {
            return tokens;
        }

        if (isEmpty(tokens)) {
            Token firstToken;
            firstToken.content = inputHead.value();
            firstToken.lineNumber = 1;
            firstToken.column = 1;

            tokens.push_back(firstToken);

            return _tokenizeInput(tokens, inputTail.value());
        }

        auto tokenLastIndex = tokens.size() - 1;
        auto lastToken = tokens.at(tokenLastIndex);

        // if valid
        auto concatedToken = lastToken.content + inputHead.value();
        if (isValidToken(concatedToken)) {
            tokens.at(tokenLastIndex).content = concatedToken;
        } else {
            Token nextToken;
            nextToken.content = inputHead.value();
            nextToken.lineNumber = 1;
            nextToken.column = 1;

            tokens.push_back(nextToken);
        }

        if (isEmpty(inputTail)) {
            return tokens;
        }

        return _tokenizeInput(tokens, inputTail.value());
    };

    auto tokenizeInput (string input) -> vector<Token> {
        vector<Token> startTokenVector = {};
        return _tokenizeInput(startTokenVector, input);
    };

    auto tokenVectorToStringVector (vector<Token> tokens) -> vector<string> {
        vector<string> result = {};

        for(auto const& token: tokens) {
            result.push_back(token.content);
        }

        return result;
    };
}

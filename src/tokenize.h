#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

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
        isResolvedString,
        isUnresolvedString
    };
}

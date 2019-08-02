#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

const vector<string> operators = {
    "+",
    "-",
    "*",
    "/",
    "?",
    "."
};

auto isOperator(string str) -> bool {
    return find(operators.begin(), operators.end(), str) != operators.end();
};

namespace tokenize {

    struct tokenizeStep {
        vector<string> tokens;
        string input;
    };

    auto isVar (string input) -> bool {
        if(isOperator(input)) return false;

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

    auto isResolvedString (string input) -> bool {
        return false;
    };

    auto isUnresolvedString (string input) -> bool {
        return false;
    };

    auto isResolvedComment (string input) -> bool {
        return false;
    };

    auto isUnresolvedComment (string input) -> bool {
        return false;
    };

    auto isWhitespace (string input) -> bool {
        return false;
    };

    typedef function<bool(string)> TokenCheckFunc;

    vector<TokenCheckFunc> tokenChecker = {
        isVar,
        isType,
        isResolvedString,
        isUnresolvedString
    };

    auto t() -> int {
        return 7;
    }
}

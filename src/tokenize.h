#include <functional>
#include <vector>
#include <string>
#include <regex>

using namespace std;

namespace tokenize {

    struct tokenizeStep {
        vector<string> tokens;
        string input;
    };

    auto isVar (string input) -> bool {
        regex prefixRex;
        prefixRex = "^([a-z|\?|$|*]+|-[a-zA-Z|\?|$|*|-])(.)*";

        regex allRex;
        allRex = "[a-zA-Z0-9|\?|$|*|-]+";

        return (regex_match(input, prefixRex) && regex_match(input, allRex));
    };

    auto isType (string input) -> bool {
        return false;
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

    typedef function<bool(string)> TokenizeFunc;

    vector<TokenizeFunc> tokenChecker = {
        isVar,
        isType,
        isResolvedString,
        isUnresolvedString
    };

    // template <typename T>
    // auto isEqual(T x, T y) -> bool {
    //     if (x == y) {
    //         return true;
    //     }
    //     throw invalid_argument( "wrong" );
    // }

   // auto tokenizeVariable(string[] tokens, string input) ->

    auto t() -> int {
        return 7;
    }
}

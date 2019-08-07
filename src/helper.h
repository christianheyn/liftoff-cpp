#include <string>
#include <vector>
#include <optional>

using namespace std;

namespace helper {

    // isEmpty =========================================
    auto isEmpty (string xs) -> bool {
        return (xs.size() == 0);
    };

    template <typename T>
    auto isEmpty (vector<T> xs) -> bool {
        return (xs.size() == 0);
    };

    template <typename T>
    auto isEmpty (optional<T> x) -> bool {
        optional<T> y = {};
        return (x == y);
    };

    // ===============================================

    auto head (string xs) -> optional<string> {
        if (isEmpty(xs)) return {};

        string result;
        result.push_back(xs.front());
        return result;
    };

    template <typename T>
    auto head (vector<T> xs) -> optional<T> {
        if (isEmpty(xs)) return {};

        return xs.front();
    };

    auto init (string xs) -> string {
        if (isEmpty(xs)) return "";

        auto result = xs.substr(0, xs.size() - 1);
        return result;
    };

    auto last (string xs) -> string {
        if (isEmpty(xs)) return "";

        string result;
        result.push_back(xs.back());
        return result;
    };

    auto tail (string xs) -> optional<string> {
        if (isEmpty(xs) || xs.size() == 1) return {};

        auto result = xs.substr(1, xs.size());
        return result;
    };
}
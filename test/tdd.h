#include <iostream>
#include <functional>
#include <stdexcept>

using namespace std;

namespace tdd {
    typedef function<void()> Func;

    template <typename T>
    auto printError(string errorMsg, T x, T y) -> void {
        try {
            auto output = "";
            cout << endl;
            cout << "    " << errorMsg << " expected: `" << x << "`, actual `" << y << "`" << endl;

        } catch (const logic_error& e) {}
    }

    template <typename T>
    auto isEqual(T expected, T actual) -> void {
        if (expected == actual) {
            return;
        }
        printError("⚖️  not equal", expected, actual);
        throw logic_error("");
    }

    template <typename T>
    auto isNotEqual(T expected, T actual) -> void {
        if (expected != actual) {
            return;
        }
        printError("equal", expected, actual);
        throw logic_error("");
    }

    auto describe(string msg, Func itFunction) {
        cout << "\x1B[43m" << "\x1B[30m " << msg << " \x1B[0m" << endl;
        itFunction();
    }

    auto it(string msg, Func itFunction) {
        try {
            itFunction();
            cout << "    ✅  " << "\x1B[32m" << msg << "\x1B[0m" << endl;
        } catch (const logic_error& e ) {
            cout << "    ❌  " << "\x1B[31m" << msg << "\x1B[0m" << endl;
            cout << endl;
        }
    }
}

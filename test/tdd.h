#include <iostream>
#include <functional>
#include <stdexcept>
#include <string>
#include <regex>

using namespace std;

namespace tdd {
    typedef function<void()> Fn;

    template <typename T>
    auto isEqual(T x, T y) -> bool {
        if (x == y) {
            return true;
        }

        throw invalid_argument( "wrong" );
    }

    template <typename T>
    auto isNotEqual(T x, T y) -> bool {
        if (x != y) {
            return true;
        }

        throw invalid_argument( "wrong" );
    }

    auto describe(string msg, Fn lambda) {
        cout << "\x1B[43m" << "\x1B[30m " << msg << " \x1B[0m" << endl;
        lambda();
    }

    auto it(string msg, Fn lambda) {
        try {
            lambda();
            cout << "    ✅ " << "\x1B[32m" << msg << "\x1B[0m" << endl;
        } catch (const std::invalid_argument& e ) {
            cout << "    ❌ " << "\x1B[31m" << msg << "\x1B[0m" << endl;
            throw;
        }
    }
}

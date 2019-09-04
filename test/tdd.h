#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

const auto colorRed = "\x1B[31m";
const auto colorGreen = "\x1B[32m";
const auto colorBlue = "\033[0;34m";
const auto colorNo = "\x1B[0m";

namespace tdd {
    typedef function<void()> Func;

    int testsPassAmount = 0;
    int testsFailAmount = 0;
    int testsTodoAmount = 0;

    template <typename T, typename T2>
    auto printError(string errorMsg, T x, T2 y) -> void {
        try {
            auto output = "";
            cout << endl;
            // TODO: print vector
        } catch (const logic_error& e) {}
    }

    template <typename T, typename T2>
    auto isEqual(T expected, T2 actual) -> void {
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
        cout << endl;
        cout << "\x1B[43m" << "\x1B[30m " << msg << " " << colorNo << endl;
        itFunction();
    }

    auto it(string msg, Func itFunction) {
        try {
            itFunction();
            cout  << colorGreen << "   PASS: " << msg << colorNo << endl;
            testsPassAmount++;
        } catch (const logic_error& e ) {
            cout << colorRed << "   FAIL: " <<  msg << colorNo << endl;
            cout << endl;
            testsFailAmount++;
        }
    }

    auto todo(string msg, Func itFunction) {
        cout <<  colorBlue <<  "   TODO: " << msg << colorNo << endl;
        testsTodoAmount++;
    }

    auto summary() -> void {
        cout << "========================" << endl;
        cout << testsPassAmount << colorGreen << " passed" << colorNo << endl;

        if (testsFailAmount > 0) {
            cout << testsFailAmount << colorRed << " failed" << colorNo << endl;
        }

        if (testsTodoAmount > 0) {
            cout << testsTodoAmount << colorBlue << " todo" << colorNo << endl;
        }

        cout << "========================" << endl;
    };
}

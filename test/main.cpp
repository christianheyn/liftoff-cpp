#include "./tdd.h"
#include "tokenizeTest.h"
#include "helperTest.h"

using namespace tdd;

auto main () -> int {
    helperTest();
    tokenizeTest();
    summary();
}

#include "./tdd.h"

using namespace tdd;

auto main () -> int {
    describe("Feature A", [](){
        it("first Test!", [](){
            isEqual(2, 2);
        });

        it("second Test!", [](){
            isEqual(2, 2);
        });
    });
}

#include <vector>

using namespace tdd;

auto helperTest () -> void {
    describe("isEmpty <string>", [](){
        it("returns true when input string is empty", [](){
            auto actual = isEmpty("");
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns false input string is not empty", [](){
            auto actual = isEmpty("a");
            auto expetced = false;
            isEqual(actual, expetced);
        });
    });

    describe("isEmpty <vector>", [](){
        it("returns true when input vector is empty", [](){
            vector<int> a = {};
            auto actual = isEmpty(a);
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns false when input vector is not empty", [](){
            vector<int> a = { 1, 2 };
            auto actual = isEmpty(a);
            auto expetced = false;
            isEqual(actual, expetced);
        });
    });

    describe("head <string>", [](){
        it("returns empty string when input string is empty", [](){
            auto actual = isEmpty(head(""));
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns first char but as string", [](){
            auto actual = head("abc");
            auto expetced = "a";
            isEqual(actual, expetced);
        });
    });

    describe("head <vector>", [](){
        it("returns when input vector is empty", [](){
            vector<int> a = {};
            auto actual = isEmpty(a);
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns false when input vector is not empty", [](){
            vector<int> a = { 1, 2 };
            auto actual = isEmpty(a);
            auto expetced = false;
            isEqual(actual, expetced);
        });
    });

    describe("last", [](){
        it("returns empty string when input string is empty", [](){
            auto actual = last("");
            auto expetced = "";
            isEqual(actual, expetced);
        });

        it("returns first char but as string", [](){
            auto actual = last("abc");
            auto expetced = "c";
            isEqual(actual, expetced);
        });
    });

    describe("last <vector>", [](){
        todo("returns when input vector is empty", [](){
            vector<int> a = {};
            auto actual = isEmpty(a);
            auto expetced = true;
            isEqual(actual, expetced);
        });

        todo("returns false when input vector is not empty", [](){
            vector<int> a = { 1, 2 };
            auto actual = isEmpty(a);
            auto expetced = false;
            isEqual(actual, expetced);
        });
    });

    describe("init", [](){
        it("returns empty string when input string is empty", [](){
            auto actual = init("");
            auto expetced = "";
            isEqual(actual, expetced);
        });

        it("returns initial string", [](){
            auto actual = init("abc");
            auto expetced = "ab";
            isEqual(actual, expetced);
        });
    });

    describe("tail", [](){
        it("returns empty string when input string is empty", [](){
            auto actual = isEmpty(tail(""));
            auto expetced = true;
            isEqual(actual, expetced);
        });

        it("returns last part of string", [](){
            auto actual = tail("abc");
            auto expetced = "bc";
            isEqual(actual, expetced);
        });
    });
};

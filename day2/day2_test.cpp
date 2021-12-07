#include <cassert>
#include "day2.cpp"

namespace day_2 {
    const char *kFilenameTest = "../day2/input_test.txt";

    void TestPartOne() {
        int result = PartOne(ReadStringFile(kFilenameTest));

        assert(result == 150);
    }

    void TestPartTwo() {
        int result = PartTwo(ReadStringFile(kFilenameTest));

        assert(result == 900);
    }

    void TestRealPart1() {
        int result = PartOne(ReadStringFile(kFilename));

        assert(result == 2027977);
    }

    void TestRealPart2() {
        int result = PartTwo(ReadStringFile(kFilename));

        assert(result == 1903644897);
    }


    void RunTests() {
        day_2::TestPartOne();
        day_2::TestPartTwo();
        day_2::TestRealPart1();
        day_2::TestRealPart2();
    }
}

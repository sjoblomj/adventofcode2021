#include <cassert>
#include "day3.cpp"

namespace day_3 {
    const char *kFilenameTest = "../day3/input_test.txt";

    void TestPartOne() {
        int result = PartOne(ReadStringFile(kFilenameTest));

        assert(result == 198);
    }

    void TestPartTwo() {
        int result = PartTwo(ReadStringFile(kFilenameTest));

        assert(result == 230);
    }

    void TestRealPart1() {
        int result = PartOne(ReadStringFile(kFilename));

        assert(result == 1458194);
    }

    void TestRealPart2() {
        int result = PartTwo(ReadStringFile(kFilename));

        assert(result == 2829354);
    }


    void RunTests() {
        day_3::TestPartOne();
        day_3::TestPartTwo();
        day_3::TestRealPart1();
        day_3::TestRealPart2();
    }
}

#include <cassert>
#include "day1.cpp"

namespace day_1 {
    const char *kFilenameTest = "../day1/input_test.txt";

    void TestCanComputeIncreases() {
        vector<int> measurements = ReadIntFile(kFilenameTest);

        int increases = day_1::ComputeNumberOfIncreases(measurements);

        assert(increases == 7);
    }

    void TestCanComputeIncreasesForSlidingWindowedMeasurements() {
        vector<int> measurements = ReadIntFile(kFilenameTest);

        int increases = day_1::ComputeNumberOfIncreases(day_1::SumToSlidingWindow(measurements));

        assert(increases == 5);
    }

    void TestRealPart1() {
        int increases = ComputeNumberOfIncreases(ReadIntFile(kFilename));

        assert(increases == 1215);
    }

    void TestRealPart2() {
        int increases = ComputeNumberOfIncreases(SumToSlidingWindow(ReadIntFile(kFilename)));

        assert(increases == 1150);
    }


    void RunTests() {
        day_1::TestCanComputeIncreases();
        day_1::TestCanComputeIncreasesForSlidingWindowedMeasurements();
        day_1::TestRealPart1();
        day_1::TestRealPart2();
    }
}

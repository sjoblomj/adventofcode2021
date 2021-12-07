#include <iostream>
#include <vector>
#include "../utils.h"

using namespace std;

namespace day_1 {
    const char* kFilename = "../day1/input.txt";
    const int kSlidingWindowSize = 3;

    namespace {
        int ComputeNumberOfIncreases(vector<int> measurements) {
            int number_of_increases = 0;
            for (int i = 1; i < measurements.size(); ++i)
                number_of_increases += measurements[i] > measurements[i - 1];

            return number_of_increases;
        }

        vector<int> SumToSlidingWindow(vector<int> measurements) {
            vector<int> out;
            out.reserve(measurements.size() - kSlidingWindowSize + 1);

            for (int i = 0; i < measurements.size() - kSlidingWindowSize + 1; ++i)
                out.push_back(measurements[i] + measurements[i + 1] + measurements[i + 2]);
            return out;
        }
    }

    void Solve() {
        vector<int> measurements = ReadIntFile(kFilename);
        cout << "Part 1: " << ComputeNumberOfIncreases(measurements) << endl;
        cout << "Part 2: " << ComputeNumberOfIncreases(SumToSlidingWindow(measurements)) << endl;
    }
}

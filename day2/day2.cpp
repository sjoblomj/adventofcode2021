#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_2 {
    const char *kFilename = "../day2/input.txt";

    namespace {
        bool isForward(string str) { return str[0] == 'f'; }
        bool isDown   (string str) { return str[0] == 'd'; }
        bool isUp     (string str) { return str[0] == 'u'; }
        int getNumber(const string& str) {
            return stoi(str.substr(str.find(' ') + 1));
        }

        int PartOne(const vector<string>& content) {
            int x = 0, y = 0;
            for (auto & i : content) {
                int num = getNumber(i);

                if (isForward(i))
                    x += num;
                else if (isDown(i))
                    y += num;
                else if (isUp(i))
                    y -= num;
            }
            return x * y;
        }

        int PartTwo(const vector<string>& content) {
            int aim = 0, x = 0, y = 0;
            for (auto & i : content) {
                int num = getNumber(i);

                if (isForward(i)) {
                    x += num;
                    y += num * aim;
                } else if (isDown(i))
                    aim += num;
                else if (isUp(i))
                    aim -= num;
            }
            return x * y;
        }
    }

    void Solve() {
        vector<string> content = ReadStringFile(kFilename);
        cout << "Part 1: " << PartOne(content) << endl;
        cout << "Part 2: " << PartTwo(content) << endl;
    }
}

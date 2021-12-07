#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace day_3 {
    const char *kFilename = "../day3/input.txt";
    const char equality = '2';

    namespace {
        int BitsToInt(const string& bits) {
            return stoi(bits, nullptr, 2);
        }

        char MostCommonBit(const vector<string>& content, int pos) {
            int counter = 0;
            for (auto &i: content)
                counter += i[pos] == '1';

            if (counter * 2 == content.size())
                return equality;
            return counter * 2 > content.size() ? '1' : '0';
        }

        string MostCommonBitString(const vector<string>& content) {
            string out;
            for (int i = 0; i < content[0].size(); ++i)
                out += MostCommonBit(content, i);
            return out;
        }

        string NegateBits(const string& bits) {
            string out;
            for (char bit : bits)
                out += bit == '0' ? '1' : '0';
            return out;
        }

        int PartOne(const vector<string>& content) {
            string most_common_bit = MostCommonBitString(content);
            string negated_bits = NegateBits(most_common_bit);

            int gamma = BitsToInt(most_common_bit);
            int epsilon = BitsToInt(negated_bits);

            return gamma * epsilon;
        }

        string FilterUntilReadingIsFound(const vector<string>& content, bool (*lambda) (char, char)) {
            vector<string> readings_left;
            copy (content.begin(), content.end(), back_inserter(readings_left));

            for (int i = 0; i < content.size(); ++i) {
                vector<string> tmp;
                char most_common_bit = MostCommonBit(readings_left, i);
                copy_if(readings_left.begin(), readings_left.end(), back_inserter(tmp),
                        [&most_common_bit, &i, &lambda](const string& s){ return lambda(s[i], most_common_bit); } );

                readings_left = tmp;
                if (readings_left.size() == 1)
                    return readings_left[0];
            }
            return "0";
        }


        int OxygenGeneratorRating(const vector<string>& content) {

            auto lambda = [](char bit, char most_common_bit) {
                char wanted_bit = most_common_bit == equality ? '1' : most_common_bit;
                return bit == wanted_bit;
            };

            string oxygen_generator_rating = FilterUntilReadingIsFound(content, lambda);
            return BitsToInt(oxygen_generator_rating);
        }

        int CO2ScrubberRating(const vector<string>& content) {
            auto negating_lambda = [](char bit, char most_common_bit) {
                char wanted_bit = most_common_bit == equality ? '1' : most_common_bit;
                return bit == (wanted_bit == '0' ? '1' : '0');
            };

            string co2_scrubber_rating = FilterUntilReadingIsFound(content, negating_lambda);
            return BitsToInt(co2_scrubber_rating);
        }

        int PartTwo(const vector<string>& content) {
            return OxygenGeneratorRating(content) * CO2ScrubberRating(content);
        }
    }

    void Solve() {
        vector<string> content = ReadStringFile(kFilename);
        cout << "Part 1: " << PartOne(content) << endl;
        cout << "Part 2: " << PartTwo(content) << endl;
    }
}

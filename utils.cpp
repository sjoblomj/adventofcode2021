#include <vector>
#include <fstream>
#include "utils.h"

using namespace std;

//template <class T>
vector<int> ReadIntFile(const char* filename) {
    ifstream infile(filename);

    vector<int> measurements;
    int m;
    while (infile >> m)
        measurements.push_back(m);
    return measurements;
}

vector<string> ReadStringFile(const char* filename) {
    ifstream infile(filename);

    vector<string> measurements;
    for (string line; getline(infile, line); )
        measurements.push_back(line);
    return measurements;
}

#include <ctime>
#include "day1/day1.cpp"
#include "day2/day2.cpp"
#include "day3/day3.cpp"

using namespace std;

void CallSolver(int day, void (*solver) ()) {
    clock_t start_time = clock();

    cout << "== Day " << day << " ==" << endl;
    solver();

    clock_t end_time = clock();
    cout << "Finished day " << day << " in " << end_time - start_time << " ms" << endl << endl;
}

int main() {
    CallSolver(1, day_1::Solve);
    CallSolver(2, day_2::Solve);
    CallSolver(3, day_3::Solve);
}

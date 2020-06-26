#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<int> a(50, 0);
    int N = 5;
    double lo = 100, hi = 200;
    for (int i = 0; i < N; ++i) {
        double x = lo + (rand() % ((int)hi - (int) lo)) / 100.0;
        cout << x << " ";
    }
    cout << endl;
    cout << true && false || true && true;
    return 0;
}
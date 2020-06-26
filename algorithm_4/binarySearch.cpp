#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class BinarySearch {
public:
    int rank(int key, vector<int> a) {
        int lo = 0;
        int hi = a.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid]) hi = mid - 1;
            else if (key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }
};

int main() {
    vector<int> a(50, 0);
    iota(a.rbegin(), a.rend(), 15);
    int key = 39;
    BinarySearch solver;
    cout << solver.rank(key, a) << endl;
    return 0;
}
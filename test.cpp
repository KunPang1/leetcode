#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<int> num(10);
        iota(num.begin(), num.end(), 1);
        for (int i = 0; i < n; ++i) {
            int temp = 1, j = n - i - 1;
            while (j > 0) {
                temp = temp * j;
                j--;
            }
            int ans = k / temp;
            if (k != 0 && k % temp == 0) ans -= 1;
            char tmp = num[ans] + '0';
            res += tmp;
            num.erase(num.begin()+ans);
            k -= ans * temp;
            if (ans == 0) k = 0;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    Solution solver;
    auto x = solver.getPermutation(3, 2);
    cout << x << endl;
    return 0;
}
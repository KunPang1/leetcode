#include <iostream>

using namespace std;

class Solution {
public:
    // 计算两个非负整数p和q的最大公约数:若q是0,则最大公约数为p。否则,将p除以
    // q得到余数r,P和q的最大公约数即为q和r的最大公约数。
    int gcd(int p, int q) {
        if (q == 0)
            return p;
            int r = p % q;
            return gcd(q, r);
    }
};

int main() {
    int p, q;
    cin >> p >> q;
    Solution solver;
    cout << solver.gcd(p, q) << endl;
    return 0;
}
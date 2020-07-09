#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<string> res;
    void backtracking(string s, string out, int index) {
        if (index == 4 && out.size() - 3 == s.size()) {
            res.push_back(out);
            return;
        }
        int temp = out.size() - index;
        if (s.size() - temp > (4 - index) * 3) return;
        for (int i = temp; i < temp + 3 && i < s.size(); i++) {
            string x = s.substr(temp, i - temp + 1);
            if (stoi(x) > 255) continue;
            if (index < 3) x += '.';
            out += x;
            backtracking(s, out, index + 1);
            out.erase(out.end() - x.size(), out.end());
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, "", 0);
        return res;
    }
};

int main() {
    vector<vector<int>> nums;
    Solution solver;
    auto x = solver.restoreIpAddresses("25525511135");
    // cout << x << endl;
    return 0;
}
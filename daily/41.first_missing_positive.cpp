#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        sort(nums.begin(), nums.end());

        int count = 1;
        for (int i : nums) {
            if (i > 0 && i > count)
                return count;
            else if (i > 0 && i == count) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums;
    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
        if (cin.get() == '\n') break;
    }
    Solution solver;
    auto x = solver.firstMissingPositive(nums);
    cout << x << endl;
    return 0;
}
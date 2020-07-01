#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

class Solution {
    int num;
    void dfs(vector<int>& nums, int cur_s, int index) {
        if (index == nums.size()) {
            num = cur_s == 0 ? num + 1 : num;
            return;
        }
        dfs(nums, cur_s - nums[index], index + 1);
        dfs(nums, cur_s + nums[index], index + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        num = 0;
        dfs(nums, S, 0);
        return num;
    }
};

int main()
{
    vector<int> nums({1, 1, 1, 1, 1});
    int k = 3;
    int temp;
    // while (cin >> temp) {
    //     nums.push_back(temp);
    //     if (cin.get() == '\n') break;
    // }
    // cin >> k;
    Solution solver;
    auto x = solver.findTargetSumWays(nums, k);
    cout << x << endl;
    return 0;
}

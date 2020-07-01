#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // 自上而下
    int maxCoins(vector<int>& nums) {

        // reframe the problem
        int n = nums.size() + 2;
        vector<int> new_nums(n, 1);

        for(int i = 0; i < nums.size(); i++){
            new_nums[i+1] = nums[i];
        }

        // cache the results of dp
        vector<vector<int>> memo(n, vector<int>(n));

        // find the maximum number of coins obtained from adding all balloons from (0, len(nums) - 1)
        return dp(memo, new_nums, 0, n - 1);
    }

    int dp(vector<vector<int>>& memo, vector<int>& nums, int left, int right) {
        // no more balloons can be added
        if (left + 1 == right) return 0;

        // we've already seen this, return from cache
        if (memo[left][right] > 0) return memo[left][right];

        // add each balloon on the interval and return the maximum score
        int ans = 0;
        for (int i = left + 1; i < right; ++i)
            ans = max(ans, nums[left] * nums[i] * nums[right]
                      + dp(memo, nums, left, i) + dp(memo, nums, i, right));
        // add to the cache
        memo[left][right] = ans;
        return ans;
    }

    
    // 自下而上
    int maxCoins_1(vector<int>& nums) {
        // reframe the problem
        int n = nums.size() + 2;
        vector<int> new_nums(n, 1);

        for(int i = 0; i < nums.size(); i++){
            new_nums[i+1] = nums[i];
        }

        // dp will store the results of our calls
        vector<vector<int>> dp(n, vector<int>(n));

        // iterate over dp and incrementally build up to dp[0][n-1]
        for (int left = n-2; left > -1; left--)
            for (int right = left+2; right < n; right++) {
                for (int i = left + 1; i < right; ++i)
                    // same formula to get the best score from (left, right) as before
                    dp[left][right] = max(dp[left][right],
                    new_nums[left] * new_nums[i] * new_nums[right] + dp[left][i] + dp[i][right]);
            }

        return dp[0][n - 1];
    }
};

int main() {
    vector<int> nums;
    Solution solver;
    auto x = solver.maxCoins(nums);
    cout << x << endl;
    return 0;
}
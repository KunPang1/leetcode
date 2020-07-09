#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else{
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0) return 0;
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b) { 
            if (a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0]; 
            });
        vector<int> temp(n, 0);
        for (int i = 1; i < n; i++) {
            temp[i] = envelopes[i][1];
        }
        return lengthOfLIS(temp);
    }
};

int main() {
    vector<vector<int>> nums = {{1, 1}, {1, 1}, {1, 1}};
    Solution solver;
    auto x = solver.maxEnvelopes(nums);
    cout << x << endl;
    return 0;
}
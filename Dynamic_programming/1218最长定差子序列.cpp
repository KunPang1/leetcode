#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> memo;
        int max_length = 1;
        for (int x : arr) {
            max_length = max(max_length, memo[x] = memo[x - difference] + 1);
        }
        return max_length;
    }
};

int main() {
    vector<int> nums;
    int difference;
    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
        if (cin.get() == '\n') break;
    }
    cin >> difference;
    Solution solver;
    auto x = solver.longestSubsequence(nums, difference);
    cout << x << endl;
    return 0;
}
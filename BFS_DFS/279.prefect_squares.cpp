#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution
{
    unordered_set<int> square_nums_1;
    bool is_divided_by(int n, int count)
    {
        if (count == 1)
            return square_nums_1.count(n);

        for (int square : square_nums_1)
        {
            if (is_divided_by(n - square, count - 1))
                return true;
        }
        return false;
    }

public:
    // 贪心枚举
    int numSquares_1(int n)
    {
        square_nums_1.clear();
        for (int i = 1; i * i <= n; ++i)
            square_nums_1.insert(i * i);
        int count = 1;
        for (; count <= n; ++count)
        {
            if (is_divided_by(n, count))
                return count;
        }
        return count;
    }
    // 贪心 + BFS
    int numSquares_3(int n)
    {

        vector<int> square_nums;
        for (int i = 1; i * i <= n; ++i)
        {
            square_nums.push_back(i * i);
        }

        unordered_set<int> q;
        q.insert(n);

        int level = 0;
        while (q.size() > 0)
        {
            level += 1;
            unordered_set<int> next_queue;

            for (int remainder : q)
            {
                for (int square : square_nums)
                {
                    if (remainder == square)
                    {
                        return level;
                    }
                    else if (remainder < square)
                    {
                        break;
                    }
                    else
                    {
                        next_queue.insert(remainder - square);
                    }
                }
            }
            q = next_queue;
        }
        return level;
    }
    // 动态规划 O(N * sqrt(N))
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        int max_square_index = (int)sqrt(n) + 1;
        vector<int> square_nums(max_square_index);
        for (int i = 1; i < max_square_index; ++i)
            square_nums[i] = i * i;
        for (int i = 1; i <= n; ++i)
        {
            for (int s = 1; s < max_square_index; ++s)
            {
                if (i < square_nums[s])
                    break;
                dp[i] = min(dp[i], dp[i - square_nums[s]] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    Solution solver;
    auto x = solver.numSquares(n);
    cout << x << endl;
    return 0;
}
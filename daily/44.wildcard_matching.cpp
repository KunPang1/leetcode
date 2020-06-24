#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = " " + s;
        p = " " + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i ++) {
            if (p[i] == '*') dp[0][i] = dp[0][i-1];
        }
        for (int j = 1; j <= m; j ++) {
            for (int i = 1; i <= n; i ++) {
                if (p[j] != '*') dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '?');
                else dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};

int main()
{
    string s("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba"), p("a*******b");
    s = "adceb";
    p = "*a*b";
    Solution solver;
    bool res = solver.isMatch(s, p);
    cout << res << endl;
    return 0;
}
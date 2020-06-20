#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        f[0][0] = true;
        
        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
        
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] != '*')
                {
                    if (matches(i, j))
                    {
                        f[i][j] = f[i-1][j-1];
                    }
                }
                else
                {
                    if (matches(i, j - 1))
                    {
                        f[i][j] = (f[i - 1][j] || f[i][j - 2]);
                    }
                    else
                        f[i][j] = f[i][j - 2];
                }
            }
        }
        return f[m][n];
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool firstMatch = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        if (p.size() >= 2 && p[1] == '*'){
            return (isMatch(s, p.substr(2, p.size() - 2)) || (firstMatch && isMatch(s.substr(1, s.size() - 1), p)));
        }
        else {
            return (firstMatch && isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1)));
        }
    }
};

int main()
{
    string s, p;
    cin >> s >> p;
    Solution solver;
    bool result = solver.isMatch(s, p);
    cout << result << endl;
    return 0;
}
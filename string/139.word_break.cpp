#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    unordered_set<string> wordDt;
    unordered_set<string> memo;
    bool backtracking(string s) {
        if (memo.count(s))
            return false;
        if (s == "")
            return true;
        
        for (int i = 1; i <= s.size(); ++i) {
            if (wordDt.count(s.substr(0, i))) {
                if (backtracking(s.substr(i, s.size() - i)))
                    return true;
                else
                    memo.insert(s.substr(i, s.size() - i));
            }
        }
        return false;
    }
public:
    // 带记忆的回溯法
    bool wordBreak(string s, vector<string>& wordDict) {
        wordDt = unordered_set<string> (wordDict.begin(), wordDict.end());
        return backtracking(s);
    }

    // 动态规划
    bool wordBreak1(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    string s;
    vector<string> wordDict;

    cin >> s;
    string temp;
    // 用空格隔开
    while (cin >> temp) {
        wordDict.push_back(temp);
        if (cin.get() == '\n')
            break;
    }

    Solution solver;
    auto x = solver.wordBreak(s, wordDict);
    cout << x << endl;
    return 0;
}
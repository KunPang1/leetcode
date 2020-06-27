#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    // 官方题解, BFS
    int openLock(vector<string>& deadends, string target) {
        int ex[2] = {1, -1};
        if (target == "0000") return 0;
        unordered_set<string> killed(deadends.begin(), deadends.end());
        if (killed.count("0000")) return -1;
        
        unordered_map<string, int> memo;
        queue<string> q;
        q.push("0000");
        memo["0000"] = 0;
        while (!q.empty()){
            string str = q.front();
            int num = memo[str];
            q.pop();
            for (int i = 0; i < 4; ++i) {
                for (int j : ex) {
                    string temp = str;
                    temp[i] = (temp[i] + j - '0') >= 0 ? (temp[i] + j - '0') % 10 + '0' : '9';
                    if (temp == target) return num+1;
                    if (!killed.count(temp) && !memo.count(temp)) {
                        memo[temp] = num + 1;
                        q.push(temp);
                    }
                }
            }
        }
        return memo.count(target) == 1 ? memo[target] : -1;
    }

    // 大神题解, 我自己解释一下, 只要没有8个dead的密码包住target
    // 就可以解锁. 然后就是先找相邻的8个密码, 然后去掉dead里的密码,
    // 从剩下的数字计算转到 0000 的最少次数.
    vector<string> getValidMoves(const string& sequence) 
    {
        vector<string> moves;
        for (int i = 0; i < 4; i++)
        {
            string temp = sequence;                         // +1
            temp[i] = temp[i] == '9' ? '0' : temp[i] + 1;
            moves.push_back(temp);
            temp = sequence;                                // -1
            temp[i] = temp[i] == '0' ? '9' : temp[i] - 1;
            moves.push_back(temp);
        }
        return moves;
    }
    
    int openLock1(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        if (deadset.count("0000")) 
        {
            return -1;
        }
        vector<string> movesToTarget;
        auto moves = getValidMoves(target);
        for (auto& move : moves) 
        {
            if (!deadset.count(move)) 
            {
                movesToTarget.push_back(move);
            }
        }

        if (movesToTarget.empty())              // 可以直接从deadends中看出target可不可达
        {
            return -1;
        }
        int min_stride = 40;                // 最大步长是40步（每位转动10次）
        for (auto& move : movesToTarget)        // 计算到达每个可达结果的步长，取最小
        {
            int cur_stride = 0;
            for (int i = 0; i < 4; ++i) 
            {
                int turns = move[i] - '0';
                if (turns > 5)                  // 可以倒着转，所以转动次数不会大过5
                {
                    turns = 10 - turns;
                }
                cur_stride += turns;
            }
            if (cur_stride < min_stride) 
            {
                min_stride = cur_stride;
            }
        }
        return min_stride + 1;                  // 最后加上到达target的那一步
    }
};

int main()
{
    vector<string> deadends;
    string target;
    string temp;
    while (cin >> temp) {
        deadends.push_back(temp);
        if (cin.get() == '\n') break;
    }
    cin >> target;
    Solution solver;
    auto x = solver.openLock(deadends, target);
    cout << x << endl;
    return 0;
}
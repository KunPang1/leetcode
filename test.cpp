#include <tuple>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
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
    
    int openLock(vector<string>& deadends, string target) {
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
    vector<string> deadends({"0201","0101","0102","1212","2002"});
    string target = "0202";
    Solution solver;
    auto x = solver.openLock(deadends, target);
    cout << x << endl;
    return 0;
}
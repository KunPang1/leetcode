#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        int res = len % (2 * numRows - 2);
        res = res > numRows ? res - numRows + 1 : 1;
        int c = (int)(len / (2 * numRows - 2)) + res;
        vector<vector<int>> save(numRows, vector<int>(c, 0));
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); ++i){
            save[x][y] = i + 1;
            if(i % (2 * numRows - 2) < numRows){
                x++;
            }
            else{
                y++;
                x--;
            }
        }
        string out = "";
        for(int i = 0; i < res; ++i){
            for(int j = 0; j < c; ++j){
                if(save[i][j] != 0){
                    out.push_back(s[save[i][j] - 1]);
                }
            }
        }
        return out;
    }
};

int main(){
    int n;
    int sum;
    Solution pro;
    auto a = pro.convert("LEETCODEISHIRING", 4);
    return 0;
}
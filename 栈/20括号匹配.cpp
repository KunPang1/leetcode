#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> save;
        for(auto x : s){
            int temp = 0;
            if(x == '{') temp = -3;
            if(x == '}') temp = 3;
            if(x == '(') temp = -2;
            if(x == ')') temp = 2;
            if(x == '[') temp = -1;
            if(x == ']') temp = 1;
            if(temp < 0) save.push(temp);
            else if(temp > 0){
                if(save.empty() || temp + save.top() != 0) return false;
                else save.pop();
            }
        }
        if(!save.empty()) return false;
        return true;
    }
};

int main(){
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution result;
    bool out = result.isValid("()");
    cout << out << endl;
    return 0;
}
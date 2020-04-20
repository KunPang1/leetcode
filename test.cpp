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
    string v = "/../";
    stack<string> save;
    vector<int> index;
    int position = 0;
    while((position = v.find("/", position)) != string::npos){
        index.push_back(position);
        position++;
    }
    for(int i = 0; i < index.size(); ++i){
        int res;
        if(i == index.size() - 1){
            if(index[i] != v.size() - 1)
                res = v.size() - index[i];
            else continue;
        }
        else res = index[i+1] - index[i];
        auto temp = v.substr(index[i], res);
        if(temp == "/." || temp == "/") continue;
        if(temp == "/.."){
            if(!save.empty())
                save.pop();
            continue;
        }
        save.push(temp);
    }
    string out = "";
    while (!save.empty())
    {
        out.insert(0, save.top());
        save.pop();
    }
    return 0;
}
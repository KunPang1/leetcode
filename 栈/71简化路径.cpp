#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> save;
        vector<int> index;
        int position = 0;
        while((position = path.find('/', position)) != string::npos){
            index.push_back(position);
            position++;
        }
        for(int i = 0; i < index.size(); ++i){
            int res;
            if(i == index.size() - 1){
                if(index[i] != path.size() - 1)
                    res = path.size() - index[i];
                else continue;
            }
            else res = index[i+1] - index[i];
            auto temp = path.substr(index[i], res);
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
        return out.size() == 0 ? "/" : out;
    }
};
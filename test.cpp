// set::emplace
#include <iostream>
#include <numeric>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<int> res;
    void backtracking(vector<int>& input, vector<char>& opt) {
        if (input.size() == 2)
        {
            if (opt[0] == '+')
                res.emplace_back(input[0] + input[1]);
            else if (opt[0] == '-')
                res.emplace_back(input[0] - input[1]);
            else if (opt[0] == '*')
                res.emplace_back(input[0] * input[1]);
            return;
        }
        int n = opt.size();
        for (int i = 0; i < n; i++) {
            int i1 = input[i], i2 = input[i+1];
            char o1 = opt[i];
            int temp;
            if (opt[i] == '+')
                temp = input[i] + input[i + 1];
            else if (opt[i] == '-')
                temp = input[i] - input[i + 1];
            else if (opt[i] == '*')
                temp = input[i] * input[i + 1];

            input[i] = temp;
            input.erase(input.begin() + i + 1);
            opt.erase(opt.begin() + i);

            backtracking(input, opt);
            
            input[i] = i1;
            input.insert(input.begin() + i + 1, i2);
            opt.insert(opt.begin() + i, o1);
        }
    }
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.size() == 0) return {};
        vector<int> save;
        vector<char> opt;
        for (int i = 0; i < input.size(); ++i) {
            int temp = 0;
            while (i < input.size() && isdigit(input[i])) {
                temp = temp * 10 + input[i] - '0';
                i++;
            }
            save.push_back(temp);
            if (i == input.size()) break;
            opt.push_back(input[i]);
        }
        backtracking(save, opt);
        return res;
    }
};

int main()
{
    Solution pro;
    auto x = pro.diffWaysToCompute("2*3-4*5");
    for (int i = 0; i < x.size(); ++i)
        cout << x[i] << endl;
    return 0;
}
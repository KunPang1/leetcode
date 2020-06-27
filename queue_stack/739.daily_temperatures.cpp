#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> out(T.size(), 0);
        stack<int> save;
        save.push(T.size() - 1);
        for (int i = T.size() - 2; i >= 0; i--)
        {
            while (!save.empty() && T[i] >= T[save.top()])
            {
                save.pop();
            }
            out[i] = save.empty() ? 0 : save.top() - i;
            save.push(i);
        }
        return out;
    }
};

int main()
{
    vector<int> T;
    int temp;
    while (cin >> temp)
    {
        T.push_back(temp);
        if (cin.get() == '\n')
            break;
    }

    Solution solver;
    auto x = solver.dailyTemperatures(T);
    for (int i : x)
        cout << i << " ";
    cout << endl;
    return 0;
}
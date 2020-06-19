#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string temp = "";
        for (char c : s)
        {
            if (!isalpha(c))
            {
                temp += tolower(c);
            }
        }
        int l = 0, r = temp.length() - 1;
        for (; l <= r; l++, r--)
        {
            if (temp[l] != temp[r])
                return false;
        }
        return true;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution solver;
    bool res = solver.isPalindrome(str);
    cout << res << endl;
    return 0;
}
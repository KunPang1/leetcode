#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        for (; l <= r; l++, r--)
        {
            while (!isalnum(s[l]) && l <= r)
                l++;
            while (!isalnum(s[r]) && l <= r)
                r--;
            if (l > r) break;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
        }
        return true;
    }
};

int main()
{
    string str;
    getline(cin, str);
    Solution solver;
    bool res = solver.isPalindrome(str);
    cout << res << endl;
    return 0;
}
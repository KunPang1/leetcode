#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    void KMP(vector<int>& next, string needle) {
        int k = -1;
        int j = 0;
        next[0] = -1;
        while (j < needle.size() - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                ++j;
                ++k;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        vector<int> next(needle.size());
        KMP(next, needle);
        next[0] = 0;
        int i = 0, j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            }
            else {
                if (j == 0) i++;
                else j = next[j];
            }
        }
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }
};

int main() {
    string str1 = "mississippi", str2 = "issip";
    Solution solver;
    auto x = solver.strStr(str1, str2);
    cout << x << endl;
}
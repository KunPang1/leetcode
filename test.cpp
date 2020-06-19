// set::emplace
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        stack<int> st1;
        st1.push(-1);
        int score = 0;
        for(int i = 0; i < A.size(); ++i){
            while(st1.top() != -1 && A[st1.top()] < A[i]){
                int temp = st1.top();
                st1.pop();
                if(st1.top() == -1) continue;
                score = max(score, A[st1.top()] + A[temp] + st1.top() - temp);
            }
            st1.push(i);
        }
        while(st1.top() != -1){
            int temp = st1.top();
            st1.pop();
            if(st1.top() != -1) break;
            score = max(score, A[st1.top()] + A[temp] + st1.top() - temp);
        }
        return score;
    }
};

int main()
{
    vector<string> temp{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<int> A({1, 2});
    Solution pro;
    auto x = pro.maxScoreSightseeingPair(A);
    return 0;
}
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> save;
        save.push(-1);
        int maxarea = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(save.top() != -1 && heights[save.top()] >= heights[i]){
                int index = save.top();
                save.pop();
                maxarea = max(maxarea, heights[index] * (i - save.top() - 1));
            }
            save.push(i);
        }
        while(save.top() != -1){
            int index = save.top();
            save.pop();
            int area = heights[index] * (heights.size() - save.top() - 1);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution pro;
    auto x = pro.largestRectangleArea(heights);
    cout << x << endl;
    return 0;
}
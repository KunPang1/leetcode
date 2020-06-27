#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// 这道题在标签栈中，但是这个栈的思路太变态了，想不到，直接抄题解
// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode/
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

// 还是用分治吧，找最矮处两侧的最大面积，但是分治也超出时间限制了，只能用栈了
// 怪不得要放在栈标签底下
class Solution {
public:
    int calculateArea(vector<int>& heights, int start, int end){
        if(start > end)
            return 0;
            int minindex = start;
            for(int i = start; i <= end; ++i)
                if(heights[minindex] > heights[i])
                    minindex = i;
            return max(heights[minindex] * (end - start + 1), max(calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end)));
    }
    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights, 0, heights.size() - 1);
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution pro;
    auto x = pro.largestRectangleArea(heights);
    cout << x << endl;
    return 0;
}
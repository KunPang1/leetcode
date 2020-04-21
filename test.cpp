#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> windows;
        int out = 0;
        int match = 0;
        while(right < nums.size()){
            int c1 = nums[right];
            if(c1 % 2 == 1){
                if(match == k){
                    out++;
                    while(true){
                        int c2 = nums[left];
                        if(c2 % 2 == 1){
                            out++;
                            windows[c2]--;
                            left++;
                            windows[c1]++;
                            right++;
                            break;
                        }
                        else{
                            out++;
                            windows[c2]--;
                            left++;
                        }
                    }
                }
                else{
                    windows[c1]++;
                    right++;
                    match++;
                }
            }
            else{
                if(match == k)
                    out++;
                windows[c1]++;
                right++;
            }
        }
        return out;
    }
};

int main(){
    vector<int> heights = {2,2,2,1,2,2,1,2,2,2};
    Solution pro;
    auto x = pro.numberOfSubarrays(heights, 2);
    cout << x << endl;
    return 0;
}
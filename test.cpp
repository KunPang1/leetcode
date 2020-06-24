// set::emplace
#include <iostream>
#include <numeric>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    int fib(int N) {
        int count = 0;
        for(int i = 1; i <= N; ++i){
            double goldenRatio = (1 + sqrt(5)) / 2;
            int num = (int)round(pow(goldenRatio, N)/ sqrt(5));
            string temp = to_string(num);
            for(char x : temp){
                if(x == '1')
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution pro;
    int x = pro.fib(n);
    cout << x << endl;
    return 0;
}
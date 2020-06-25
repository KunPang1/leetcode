#include <iostream>
#include <bitset>

using namespace std;

// 进制表示
/*
* 二进制: 0b
* 八进制: 0
* 十六进制: 0x

* 1.二进制
* int x = 0b1001;   // x = 9
* 2.八进制
* int y = 074;      // x = 60
* 3.十六进制
* int z = 0xa3;     // x = 163;

* 初次之外在char类型字符的表示时也可以用 8进制数 或 16进制数，
* 例: char A = '\101'  这里 以\开头表述其后为八进制数 最终 '\101' == 65 == 'A' 
* 例: char B = '\x42' 这里 以\x开头表述其后为十六进制数 最终 '\x42' == 66 == 'B' 
*/

// 取反
/**
 * int占4个字节，共32位
 * 1 的二进制是 0000 0000 0000 0000 0000 0000 0000 0001
 * ~1 就是 1111 1111 1111 1111 1111 1111 1111 1110  --> -2 的补码表示
 * 所以 ~1 = -2
 * 
 * int是有符号的二进制数，第一位是0时，表示正数，是1时，表示负数，
 * 负数在内存中以补码的形式存在。补码是为了避免出现0的两个不同二进制表示创立的。
 * 这是程序将~1的二进制表示解释为了-2，不是输出的时候转换成补码，它俩只是恰好相等。
*/

class Solution {
public:
    // 求数字的补数(补数是对该数的二进制表示取反。)
    /* 
    * 1、对输入num去反，取反后二进制数字第一个1前面的零均变为1，这bit的1变为0。
    * 所有要将去反后第一个0前面的1删除
    * eg. 0x05=0000000000000101 取反：1111111111111010那么需要将第一个零1111111111111010 前面的1删掉
    * 2、删除1前面的0:使用&=~清零
    */
    int findComplement(int num) {
        int oneNum = ~num;
        int oneBitFlag = 0x80000000;
        while((oneNum & oneBitFlag) != 0) {
                oneNum &= ~oneBitFlag;
                oneBitFlag >>= 1;
        }
        return oneNum;
    }
};

int main() 
{
    int val = 234;
    // 10进制转换为2进制
    bitset<10U> res = bitset<10>(val);

    Solution solver;
    int x = solver.findComplement(5);
    cout << val << " " << res << endl;
    return 0;
}
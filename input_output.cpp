#include<iostream>
 
using namespace std;

// 输入描述:
// 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据包括多组。
// 输出描述:
// 输出a+b的结果
int main()
{
    int a;
    int b;
    while(cin>>a>>b)
        cout<<a+b<<endl;
    return 0;
}

// 输入描述:
// 输入第一行包括一个数据组数t(1 <= t <= 100)
// 接下来每行包括两个正整数a,b(1 <= a, b <= 10^9)
// 输出描述:
// 输出a+b的结果
int main(){
    int row;
    cin>>row;
    for(int i = 0 ; i<row; i++){
        int a,b;
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    return 0;
}

// 输入描述:
// 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 如果输入为0 0则结束输入
// 输出描述:
// 输出a+b的结果
int main(){
    int a,b;
    while(cin>>a>>b){
        if(a!=0&&b!=0) {
            cout<<a+b<<endl;
        }else {
            break;
        }
    }
    return 0;
}

// 输入描述:
// 输入数据包括多组。
// 每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
// 接下来n个正整数,即需要求和的每个正整数。
// 输出描述:
// 每组数据输出求和的结果
int main()
{
    int n,m;
    while(cin>>n)
    {
        if(n==0)
            break;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>m;
            sum+=m;
        }
        cout<<sum<<endl;
    }
}

// 输入描述:
// 输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
// 接下来t行, 每行一组数据。
// 每行的第一个整数为整数的个数n(1 <= n <= 100)。
// 接下来n个正整数, 即需要求和的每个正整数。
// 输出描述:
// 每组数据输出求和的结果
int main()
{
    int t;
    int n,m;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        int sum=0;
        for(int j=0;j<n;j++)
        {
            cin>>m;
            sum+=m;
             
        }
        cout<<sum<<endl;
    }
}

// 输入描述:
// 输入数据有多组, 每行表示一组输入数据。
// 每行的第一个整数为整数的个数n(1 <= n <= 100)。
// 接下来n个正整数, 即需要求和的每个正整数。
// 输出描述:
// 每组数据输出求和的结果
int main(){
    int t;
    while(cin>>t){
        int sum=0;
        while(t){
            int a;
            cin>>a;
            sum+=a;
            t--;
        }
        cout<<sum<<endl;
    }
return 0;
}

// 输入描述:
// 输入数据有多组, 每行表示一组输入数据。

// 每行不定有n个整数，空格隔开。(1 <= n <= 100)。
// 输出描述:
// 每组数据输出求和的结果
int main()
{
    int n;
    int sum=0;
    while(cin>>n)
    {
        sum+=n;
        if(cin.get()=='\n')
            {cout<<sum<<endl;sum=0;}
         
    }
}

// 输入描述:
// 输入有两行，第一行n

// 第二行是n个空格隔开的字符串
// 输出描述:
// 输出一行排序后的字符串，空格隔开，无结尾空格
int main(){
      
    int m;
    cin>>m;
    vector<string> v;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
       if(i<m-1) cout<<v[i]<<" ";
       else cout<<v[i];
    }
      
}

// 输入描述:
// 多个测试用例，每个测试用例一行。

// 每行通过空格隔开，有n个字符，n＜100
// 输出描述:
// 对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<string> ac;
    int i;
    string s;
    while(cin>>s){
        ac.push_back(s);
        if(cin.get()=='\n'){
            sort(ac.begin(),ac.end());
            for(i=0;i<ac.size();i++)
                cout<<ac[i]<<" ";
            cout<<endl;
            ac.clear();
        }
    }
    return 0;
}

// 输入描述:
// 多个测试用例，每个测试用例一行。
// 每行通过,隔开，有n个字符，n＜100
// 输出描述:
// 对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
 
int main(){
    std::string temp;
    while(std::cin >> temp) {
        std::string substr;
        std::vector<std::string> oneLine;
        std::stringstream ss(temp);
        while(ss.good()){
            getline(ss, substr, ',');
            oneLine.push_back(substr);
        }
        std::sort(oneLine.begin(), oneLine.end());
        int size = oneLine.size();
        for(int i = 0; i < size - 1; i++){
            std::cout << oneLine[i] << ',';
        }
        std::cout << oneLine[size - 1] << std::endl;
    }
}

// 输入描述:
// 输入有多组测试用例，每组空格隔开两个整数
// 输出描述:
// 对于每组数据输出一行两个整数的和

#include<iostream>
using namespace std;
int main()
{
    long long a,b;
    while(cin>>a>>b)
     
    cout<<a+b<<endl;
    return 0;
}
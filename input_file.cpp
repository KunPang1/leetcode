#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {

    // 数字
    char c;
    int sum = 0;
    while (cin >> c) {
        if (c >= '0' && c <= '9') {
            sum += (c - '0');
        }
        if (getchar() == '\n') {
            cout << sum << endl;
            sum = 0;
        }
    }

    // 字符串
    int n;
    cin >> n;
     
    string str[n];
     
    for(int i = 0; i < n; i++) cin >> str[i];
    sort(str, str + n);
 
    for(int i = 0; i < n - 1; i++) cout << str[i] << " ";
    cout << str[n - 1] << endl;

    //多行字符串
    string num, temp;
    while(cin >> num) {
        string *str = new string[100];
        int i = 0;
        while(true) {
            str[i] = num;
            if(cin.get() == '\n')    break;
            cin >> num;
            i++;
        }
        for(int j = 0; j < i+1; j++)
            for(int k = j+1; k < i+1; k++)
                if(str[k] < str[j]) {
                    temp = str[k];
                    str[k] = str[j];
                    str[j] = temp;
                }
        for(int j = 0; j < i+1; j++)
            cout << str[j] << ' ';
        cout << endl;
        delete []str;
    }
    return 0;
}

/*
对输入的字符串进行排序后输出
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
 
void spilt_line(string& s,vector<string>& v){
   auto left = s.begin();
   for(auto iter = s.begin();;){
       if(iter == s.end() || *iter == ','){
           v.push_back(string(left,iter));
           if(iter == s.end())
               break;
           while(*(++iter) == ',');
           left = iter;
       }else ++iter;
   }
}
void print_vector(vector<string>& v){
   for(int i=0;;++i){
       if(i != v.size()-1)
           cout << v[i] << ",";
       else {
           cout << v[i];
           break;
       }
   }
    cout << endl;
}
int main(){
     
    string line;
    vector<string> v;
    while(getline(cin,line)){
        spilt_line(line,v);
        sort(v.begin(),v.end());
        print_vector(v);
        v.clear();
        line.clear();
    }
}
*/
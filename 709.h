#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  709.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午11:33
*/

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0;i<str.length();i++){
            if(str[i]>='A'&&str[i]<='Z')str[i] += 32;
        }
        return str;
    }
};


/*  解决思路 & 复杂度
    水题...
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        string s = "ASDASFQWEasdasdwqf";
        cout<<ans.toLowerCase(s);
        return 0;
    }
*/
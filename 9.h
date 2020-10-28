#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  9.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-25 下午8:03 
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string ss = s;
        reverse(ss.begin(),ss.end());
        if(s==ss)return true;
        else return false;
    }
};


/*  解决思路 & 复杂度
    水题..
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        cout<<ans.isPalindrome(123)<<endl;
        return 0;
    }
*/
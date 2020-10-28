#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  7.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-23 下午10:21 
*/

class Solution {
public:
    int reverse(int x) {
        long temp = 0;
        while (x != 0) {
            int pop = x % 10;
            temp = temp * 10 + pop;
            if (temp > 2147483647|| temp < -2147483648) {
                return 0;
            }
            x /= 10;
        }
        return (int) temp;
    }
};


/*  解决思路 & 复杂度
    就是个简单的按位 乘法...
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        cout<<ans.reverse(123)<<endl;
        return 0;
    }
*/
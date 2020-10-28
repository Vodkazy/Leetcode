#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  8.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-25 下午7:50 
*/

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int flag = 1;
        int i = 0;
        // remove front spaces
        while (str[i] == ' ') ++i;
        if (str[i] == '+' || str[i] == '-') {
            flag = (str[i] == '+') ? 1 : -1;
        }else if (str[i] >= '0' && str[i] <= '9') {
            res += 10 * res + str[i] - '0';
        } else {
            return 0;
        }
        while (++i < str.size() && str[i] >= '0' && str[i] <= '9') {
            res = 10 * res + str[i] - '0';
            if (flag == 1 && res >= INT_MAX)
                return INT_MAX;
            if (flag == -1 && res * -1 <= INT_MIN)
                return INT_MIN;
        }
        return flag * res;
    }
};


/*  解决思路 & 复杂度
    题目限制了在int类型内，所以就可以用longlong来进行存储，然后具体判断一下子最大值最小值就完事了。
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        cout<<ans.myAtoi("-124124")<<endl;
        return 0;
    }
*/
#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  6.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-23 下午4:36 
*/

class Solution {
public:
    string convert(string s, int row) {
        if (row == 1) return s;
        string ret;
        int n = s.size();
        int loop = 2 * row - 2;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j + i < n; j += loop) {
                ret += s[j + i];
                if (i != 0 && i != row - 1 && j + loop - i < n)
                    ret += s[j + loop - i];
            }
        }
        return ret;
    }
};


/*  解决思路 & 复杂度
    首先访问 行 0 中的所有字符，接着访问 行 1，然后 行 2，依此类推...
    对于所有整数 k，
    行 0 中的字符位于索引 k*(2*row−2) 处;
    行 Rows−1 中的字符位于索引 k*(2*row−2)+row−1 处;
    内部的行 i 中的字符位于索引 k*(2*row−2)+i 以及 (k+1)*(2*row−2)−i 处;
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        cout<<ans.convert("PAYPALISHIRING",3)<<endl;
        return 0;
    }
*/
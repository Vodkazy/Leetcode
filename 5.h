#include <bits/stdc++.h>
/*
   @ 编写Solution :  5.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-21 下午9:57 
*/
using namespace std;

class Solution {
public:
    /* dp法
    string longestPalindrome(string s) {
        if (s == "")
            return "";
        int dp[1005][1005];
        int flag[1005][1005];
        int start = 0, len = 0;
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                dp[i][j] = 1;
                start = i;
                len = 1;
            }
        }
        for (int i = 0; i < s.length(); i++) flag[i][i] = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
                start = i;
                len = 2;
                flag[i][i + 1] = 1;
            }
        }
        int s_len = s.length();
        for (int l = 3; l <= s.length(); l++) {
            for (int i = 0; i < s.length(); i++) {
                int j = min(i + l - 1, s_len);
                if (s[i] == s[j] && flag[i + 1][j - 1] == 1) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                    flag[i][j] = 1;
                    start = i;
                    len = l;
                } else {
                    dp[i][j] = max(dp[i][j], max(dp[i + 1][j - 1], dp[i][j - 1]));
                }
            }
        }
        return s.substr(start, len);
    }*/
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return s;
        int start = 0;
        int end = 0;
        int mlen = 0;
        for (int i = 0; i < len; i++) {
            int len1 = expendaroundcenter(s, i, i);//一个元素为中心
            int len2 = expendaroundcenter(s, i, i + 1);//两个元素为中心
            mlen = max(max(len1, len2), mlen);
            if (mlen > end - start + 1) { // 更新
                start = i - (mlen - 1) / 2;
                end = i + mlen / 2;
            }
        }
        return s.substr(start, mlen);
    }

    int expendaroundcenter(string s, int left, int right) {
        int L = left;
        int R = right;
        while (L >= 0 && R < s.length() && s[R] == s[L]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};


/*  解决思路 & 复杂度
    思路一：暴力法太暴力，O(n^3)
    思路二：DP。dp[i][j] = dp[i+1][j-1]+2，O(n^2)
    思路三：中心扩展法。回文中心的两侧互为镜像。因此，回文可以从他的中心展开，并且只有 2n-1 个这样的中心（一个元素为中心的情况有 n 个，两个元素为中心的情况有 n-1 个），O(n^2)
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        string s = "ababababa";
    //    string s = "abcda";
    //    string s = "";
        cout<<ans.longestPalindrome(s)<<endl;
        return 0;
    }
*/
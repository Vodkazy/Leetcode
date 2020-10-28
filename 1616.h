#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  1616.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-11 下午11:07 
*/

class Solution {
public:
    bool judge(string c, int l, int r){
        int len = c.length();
        int left=l,right=r;
        while(left<=right)
        {
            if(c[left]==c[right])
            {
                left++;
                right--;
            }
            else
                break;
        }
        if(left>=right)
            return true;
        else
            return false;
    }

    bool checkPalindromeFormation(string a, string b) {
        int max_len1 = 0;
        int max_len2 = 0;
        int len = a.length();
        for(int i=0;i<len;i++){
            if(a[i] == b[len-1-i]){
                max_len1 += 1;
            }
            else
                break;
        }
        for(int i=0;i<len;i++){
            if(b[i] == a[len-1-i]){
                max_len2 += 1;
            }
            else
                break;
        }
        if(judge(a, max_len1, len-max_len1-1) || judge(a, max_len2, len-max_len2-1) || judge(b, max_len1, len-max_len1-1) || judge(b, max_len2, len-max_len2-1))
            return true;
        return false;
    }
};


/*  解决思路 & 复杂度
    做的时候读题一开始都没读懂（因为比赛中自动填入的第二个样例是错误的）。后来明白大体意思就是在某一点同时切割两个字符串，然后交叉拼接看是否是回文串。
    思路：给定两个字符串a和b，如果他们之间任意一个是回文的，那么在一开始的位置割，一个是空串一个是自身，成立。
    否则的话，其实就是双指针同时从a的左/右边和b的右/左边找最长相同子串（假设长度为m）。然后就有以下四种可能：
    a的开头 + b的中间 + b的结尾 （在a的左边m处切割）
    a的开头 + a的中间 + b的结尾 （在a的右边m处切割）
    b的开头 + a的中间 + a的结尾 （在b的左边m处切割）
    b的开头 + b的中间 + a的结尾 （在b的右边m处切割）
    所以抛去刚才已经找到的两个长度为m的子串，只需要判断(m, len-m-1)这个区间的子串是否是回文串即可。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        cout<<ans.checkPalindromeFormation("aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd","uvebspqckawkhbrtlqwblfwzfptanhiglaabjea")<<endl;
        return 0;
    }
*/
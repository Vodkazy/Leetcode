#include <bits/stdc++.h>
/*
   @ 编写Solution :  3.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午11:02
*/
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>ss;
        int n = s.length();
        int i=0 ,j=0;
        int maxn = 0;
        while(i<n&&j<n){
            if(ss.find(s[j])!=ss.end()){
                i=max(i,ss[s[j]]);
            }
            maxn = max(maxn,j-i+1);
            ss[s[j]]=j+1;
            j++;
        }
        return maxn;
    }
};


/*  解决思路 & 复杂度
    在暴力法中，我们会反复检查一个子字符串是否含有有重复的字符，但这是没有必要的。如果从索引i到j−1之间的子字符串s_ij已经被检查为没有重复字符。
    我们只需要检查s[j]对应的字符是否已经存在于子字符串s_ij中。具体的，用ss[]来维护字符的当前的下标，我们要尽可能的扩大区间[i,j)的长度，也就是无重复元素的子串的长度
    那么移动j，如果当前元素s[j]不在当前区间，就hash记录一下，然后继续右移；若在，则把区间左端点移到“当前这个元素上一次出现过的地方的下一个位置”。（滑动窗口）
    时间复杂度 O(n)
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        string s = "abcabcbb";
        cout<<ans.lengthOfLongestSubstring(s);
        return 0;
    }
*/
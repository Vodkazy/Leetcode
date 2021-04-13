#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  3.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午11:02
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;
        set<int>ss;
        ss.insert(s[0]);
        int head = 0;
        int tail = 1;
        int maxn = 1;
        while(tail<s.length()){
            if(ss.find(s[tail])==ss.end()){
                ss.insert(s[tail]);
            }else{
                while(s[head]!=s[tail])ss.erase(s[head]),head++;
                head++;
            }
            maxn = max(maxn, tail-head+1);
            tail++;
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

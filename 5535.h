#include <bits/stdc++.h>
/*
   @ 编写Solution :  5535.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-11 下午11:01 
*/
using namespace std;

class Solution {
public:
    int max(int a, int b){
        return a>=b?a:b;
    }

    int maxDepth(string s) {
        stack<int> st;
        int max_cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(0);
                max_cnt = max(max_cnt, st.size());
            }
            else if(s[i] == ')'){
                st.pop();
            }
        }
        return max_cnt;
    }
};


/*  解决思路 & 复杂度
    括号匹配的典型问题，堆栈维护最大值即可。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        cout<<ans.maxDepth("(1+(2*3)+((8)/4))+1");
        return 0;
    }
*/
#include <bits/stdc++.h>
/*
   @ 编写Solution :  771.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午11:26
*/
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int>m;
        int cnt = 0;
        for(int i=0;i<J.length();i++){
            m[J[i]] = 1;
        }
        for(int i=0;i<S.length();i++){
            if(m[S[i]])
                cnt++;
        }
        return cnt;
    }
};


/*  解决思路 & 复杂度
    简单的hash。。记录J中的值，去S中计数。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        string J = "aA", S = "aAAbbbb";
        cout<<ans.numJewelsInStones(J,S);
        return 0;
    }
*/
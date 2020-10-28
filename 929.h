#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  929.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 上午11:30
*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>m;
        string tem , ans ;
        for(int i=0;i<emails.size();i++){
            ans = "";
            tem = emails[i];
            bool flag = 1;
            bool flagg = 0;
            for(int j=0;j<emails[i].length();j++){
                if(emails[i][j]=='@'){
                    flag = 1;
                    flagg = 1;
                }
                if(!flag){
                    continue;
                }
                if(emails[i][j]=='.'&&!flagg){
                    continue;
                }
                if(emails[i][j]=='+'){
                    flag = 0;
                    continue;
                }
                ans += emails[i][j];
            }
            //cout<<ans<<endl;
            m.insert(ans);
        }
        return m.size();
    }
};

/*  解决思路 & 复杂度
    感觉是个模拟题，用一个set维护一下即可。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<string> v = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
        cout<<ans.numUniqueEmails(v);
        return 0;
    }
*/
#include <bits/stdc++.h>
/*
   @ 编写Solution :  17.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-26 下午4:18 
*/
using namespace std;

class Solution {
public:
    int len;
    set<string>ans;
    vector<string>return_set;
    map<char, string> m{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits=="") return res;
        len = digits.length();
        dfs("", digits, 0);
        // for(auto i=ans.begin(); i!=ans.end();i++){
        //     cout<<*i<<" ";
        // }
        return_set.assign(ans.begin(), ans.end());
        return return_set;
    }

    void dfs(string already_s, string looking_s, int step){
        if(step==len){
            ans.insert(already_s);
            return;
        }
        string candidate_string = m[looking_s[0]];
        for(int i=0;i<candidate_string.length();i++){
            dfs(already_s+candidate_string[i], looking_s.substr(1,looking_s.length()), step+1);
        }
    }
};


/*  解决思路 & 复杂度
    简单搜索，每次记录下当前状态和处于第几步。
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        ans.letterCombinations("23");
        return 0;
    }
*/
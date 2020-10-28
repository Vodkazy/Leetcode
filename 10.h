#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  10.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-25 下午8:22 
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s,p,1);
    }

    int dfs(string s, string p, int time){
//        cout<<"Time: "<<time<<endl;
//        cout<<"s: "<<s <<" , p:"<<p<<endl;
        if(s.length()==0 && p.length()==0) { // 正好匹配成功
//            cout << "1" << endl;
            return 1;
        }
        else if(s.length()==0 && p.length()>0 )  { // s走完，p分类讨论
            stack<char>st;
            for(int i = 0;i<p.length();i++){
                if(p[i]=='*' && st.top()!='*')st.pop();
                if(p[i]!='*')st.push(p[i]);
            }
//            cout << "3" << endl;
            if(st.empty())return 1; //如果最后剩的是.*c*，则*可以把栈清空
            else return 0; //如果最后剩的是.cx*，则*只能消除与之相邻的那一个字符，.依旧无法消除，体现为所有*都起作用之后栈内还是有剩余元素
        }
        else if(p.length()==0 && s.length()>0) { // p走完 s没走完
//            cout << "4" << endl;
            return 0;
        }
        if(p[0]=='.'){
            if(p.length()==1){ // p只剩一个.，s和p都直接消一个
//                cout << "5" << endl;
                return dfs(s.substr(1, s.length()-1),"",time+1);
            }
            if((p[1]>='a' && p[1]<='z') || (p[1]=='.')){ //".char"或者".."模式 sp都消一个
//                cout << "6" << endl;
                return dfs(s.substr(1, s.length()-1),p.substr(1,p.length()-1),time+1);
            }
            // ".*"，可以选择匹配0个，或者匹配一个之后再来这里递归
//            cout << "7" << endl;
            return dfs(s,p.substr(2,p.length()-2),time+1) || dfs(s.substr(1,s.length()-1),p,time+1);
        }
        else if(p[0]>='a' && p[0]<='z'){
            if(p.length()==1){ //"char" 直接匹配当前s是否是该字符
//                cout << "8" << endl;
                return s[0]==p[0] && dfs(s.substr(1, s.length()-1),"",time+1);
            }
            if((p[1]>='a' && p[1]<='z') || (p[1]=='.')){ //"char char"或者"char ."，需要判断完当前char，再消一位
//                cout << "9" << endl;
                return s[0]==p[0] && dfs(s.substr(1, s.length()-1),p.substr(1,p.length()-1),time+1);
            }
            // "char *"，可选择匹配0个，以及再次递归
//            cout << "10" << endl;
            return dfs(s,p.substr(2,p.length()-2),time+1) || (s[0]==p[0] && dfs(s.substr(1,s.length()-1),p,time+1));
        }
        return 0;
    }
};


/*  解决思路 & 复杂度
    我的做法比较丑陋，就是利用分类讨论和递归的方式做。。leetcode上有更优雅的纯递归的方式，可以去学习一下。
    我的做法速度极慢。。500多ms，66M内存。。。

    优雅的递归做法是：
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.length()>1 && p[1]=='*')
            return isMatch(s,p.substr(2)) ||
                    (!s.empty() && (s[0]==p[0]||p[0]=='.') && isMatch(s.substr(1),p));
        else return !s.empty() && (s[0]==p[0]||p[0]=='.') &&
                    isMatch(s.substr(1),p.substr(1));
    }

    dp的方法是：
    flag[0][0] = true;边界情况
    这里flag[i][j]表示pattern[0~j-1]是否可以匹配str[0~i-1],(注意flag[i][j] 对应于 pattern[j - 1] str[i - 1])，首先列出动态转移方程
    第一种情况：
    pattern[j - 1] == str[i - 1] || pattern[j - 1] == '.'
    有flag[i][j] = flag[i - 1][j - 1];
    第二种情况：
    pattern[j - 1] == '*'
    第二种情况的第一个分支
    str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.'
    有flag[i][j] = (flag[i][j - 2] || flag[i][j - 1] || flag[i - 1][j]);(三种情况分别对应：*号让前面字符出现0次、出现1次、出现2次及以上)
    第二种情况第二个分支
    flag[i][j] = flag[i][j - 2];(*号只能让前面的字符出现0次)
    第三种情况：
    flag[i][j] = false;
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        cout<<ans.isMatch("aa","a*");
    //    cout<<ans.isMatch("ab",".*c");
    //    cout<<ans.isMatch("a",".*..a*");
        return 0;
    }
*/
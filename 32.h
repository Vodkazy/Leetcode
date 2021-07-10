class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)return 0;
        int a[30005];
        memset(a,0,sizeof(a));
        stack<int>ss;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')ss.push(i);
            else{
                if(ss.empty())continue;
                a[ss.top()]=1;
                a[i] = 1;
                ss.pop();
            }
        }
        int maxn = 0;
        int now_len = (a[0]==1)?1:0;
        for(int i=1;i<s.length();i++){
            if(a[i]==0)now_len=0;
            else if(a[i-1]==0&&a[i]==1)now_len=1;
            else{
                now_len = now_len+1;
                maxn=max(maxn, now_len);
            }
        }
        return maxn;
    }
};

// 两次遍历，第一次用stack把那些能匹配上的位置都置为1，然后再遍历数组统计连续1的最长长度 

#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  5546.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-25 下午4:09 
*/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int a[10005];
        memset(a,0,sizeof(a));
        for(int i=0;i<releaseTimes.size();i++){
            if(i==0){
                a[keysPressed[i]-'a'] = max(a[keysPressed[i]-'a'],releaseTimes[i]);
                continue;
            }
            a[keysPressed[i]-'a'] =  max(a[keysPressed[i]-'a'], (releaseTimes[i]-releaseTimes[i-1]));
        }
        int maxn = 0;
        int cnt = 0;
        char max_char = 'a';
        for(int i=0;i<26;i++){
            // cout<<a[i]<<endl;
            if(a[i]>=cnt){
                cnt = a[i];
                if(max_char<(i+'a')){
                    max_char = i+'a';
                }
                maxn = i;
            }
        }
        return max_char;
        // cout<<max_char<<endl;
    }
};


/*  解决思路 & 复杂度
    第一次做的时候看错题意了，我还以为是累计时间，原来应该是每次按压的时间的最长时间
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        vector<int> releaseTimes = {9,29,49,50};
        string keysPressed = "cbcd";
        cout<< ans.slowestKey(releaseTimes, keysPressed) <<endl;
        return 0;
    }
*/
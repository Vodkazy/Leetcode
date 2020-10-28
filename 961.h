#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  961.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 下午12:59
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int ans ;
        map<int,int>m;
        for(int i=0;i<A.size();i++){
            m[A[i]]++;
            if(m[A[i]]>=2){
                ans = A[i];
                break;
            }
        }
        return  ans;
    }
};


/*  解决思路 & 复杂度
    计个数就完了。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int> a = {1,2,3,3};
        cout<<ans.repeatedNTimes(a);
        return 0;
    }
*/
#include <bits/stdc++.h>
/*
   @ 编写Solution :  905.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-6-20 下午12:57
*/
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> B;
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0)B.push_back(A[i]);
        }
        for(int i=0;i<A.size();i++){
            if(A[i]%2==1)B.push_back(A[i]);
        }
        return  B;
    }
};


/*  解决思路 & 复杂度
    遍历两遍push即可。
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int> a = {3,1,2,4};
        vector<int> b = ans.sortArrayByParity(a);
        for(int i=0;i<b.size();i++)cout<<b[i]<<" ";
        return 0;
    }
*/
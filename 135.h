#include <bits/stdc++.h>
/*
   @ 编写Solution :  135.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-6 下午9:07 
*/
using namespace std;

#define maxn 1000005
int cs[maxn];

class Solution {
public:
    int candy(vector<int>& ratings) {
        memset(cs, 0, sizeof(cs));
        for(int i = 0; i < ratings.size(); i++){
            cs[i] = 1;
        }
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                cs[i] = cs[i-1] + 1;
            }
        }
        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && cs[i] <= cs[i+1]){
                cs[i] = cs[i+1] + 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i < ratings.size(); i ++){
            cnt += cs[i];
        }
        return cnt;
    }
};


/*  解决思路 & 复杂度
    贪心的思想，相当于分开考虑从左到右的大小一致性 和 从右到左的大小一致性。
    初始化所有孩子的糖果都为1，然后从左到右遍历一遍，如果右边的孩子的评分比左边的高，就把右边孩子的糖果变为左边孩子的糖果+1
    （只考虑了从左到有的评分高的糖果多，并且不满足这个性质的糖果数量设为最少的1）
    然后考虑从右到左遍历的大小一致性，最直接的想法应该是如果左边的孩子的评分比右边的高，就把左边孩子的糖果变为右边孩子的糖果+1
    但是这样的话可能会使得 4 5 3 这种中间最高的，5这个位置的值又被写了一遍，这是不对的
    所以就需要在更新的时候添加一个限制，就是如果左边孩子评分比右边高，并且，左边孩子当前糖果不大于右边孩子时，才更新左边孩子的糖果。
    （因为比如原来的糖果是 2 3 1的话，则第三个孩子还是保持1最好，因为如果中间的孩子更新为2的话就会打破原来的大小一致性）

*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int> c = {1,0,2};
        cout<<ans.candy(c);
        return 0;
    }
*/
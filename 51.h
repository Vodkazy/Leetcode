#include <bits/stdc++.h>
/*
   @ 编写Solution :  51.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  20-10-26 下午10:28 
*/
using namespace std;

class Solution {
public:
    int num_n;
    vector<vector<string>> result;
    vector<string> cmap;
    void dfs(int row){
        if(row == num_n){
            result.push_back(cmap);
            return;
        }
        for(int col=0;col<num_n;col++){
            if(isTrue(row, col, cmap)){
                cmap[row][col] = 'Q';
                dfs(row+1);
                cmap[row][col] = '.';
            }
        }
    }

    bool isTrue(int row, int col, vector<string>& cmap){
        // 已经放过的行里有无列冲突
        for(int i=0;i<row;i++){
            if(cmap[i][col]=='Q'){
                return false;
            }
        }
        // 已经放过的行里有无45°斜冲突
        for(int i=row-1, j=col-1;j>=0&&i>=0;i--,j--){
            if(cmap[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1, j=col+1;j<num_n&&i>=0;i--,j++){
            if(cmap[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        num_n = n;
        cmap = vector<string>(num_n, string(num_n, '.'));
        dfs(0);
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                cout<<endl;
            }
            cout<<endl;
            cout<<endl;
        }
        return result;
    }
};


/*  解决思路 & 复杂度
    经典N皇后问题，主要是一个回溯的问题。
    首先暴力枚举肯定是不行的，那样的话复杂度是N^N，这就要想到记忆化搜索一下。
    我们可以把这个过程看做是从第一行（n个根节点）开始，往下不断的分支（n叉树）尝试排列的可能，很容易想到的解法就是dfs+剪枝。
    具体的思路：对于每一行，遍历它的每一列尝试放下皇后，然后继续搜下一行，搜完再回溯恢复原状态，最后到达第n+1行遍历完之后把结果返回（n皇后保证有解）
    时间复杂度应该是O(N^2)，空间复杂度O(N)

    dfs套路可以总结如下：

    dfs() {
        if (终止条件) {
            存放结果;
        }

        for (枚举同一个位置的所有可能性，可以想成节点孩子的数量) {
            递归，处理节点;
            backtracking();
            回溯，撤销处理结果
        }
    }
*/

/*  Main函数入口
    int main(){
        Solution ans = Solution();
        ans.solveNQueens(4);
        return 0;
    }
*/
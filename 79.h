class Solution {
public:
    bool flag = false;
    int vis[10][10];

    int dir[4][2] = {0,1,0,-1,-1,0,1,0};

    void dfs(vector<vector<char>>& board, string word, int index_now, int row, int col, int m, int n){
        if(index_now==word.size()-1 && board[row][col]==word[index_now]){
            flag = true;
            return;
        }
        if(board[row][col]!=word[index_now])return;
        
        for(int i=0;i<4;i++){
            int new_row = dir[i][0]+row;
            int new_col = dir[i][1]+col;
            if(new_row<0 || new_row>=m || new_col<0 || new_col>=n || vis[new_row][new_col])continue;
            vis[new_row][new_col] = 1;
            dfs(board, word, index_now+1, new_row, new_col, m, n);
            vis[new_row][new_col] = 0;
        }

    }

    bool exist(vector<vector<char>>& board, string word) {
        memset(vis,0,sizeof(vis));
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j] = 1;
                    dfs(board, word, 0, i, j, m, n);
                    vis[i][j] = 0;
                }
            }
        }
        return flag;
    }
};

// 简单dfs，传参倒是不少 

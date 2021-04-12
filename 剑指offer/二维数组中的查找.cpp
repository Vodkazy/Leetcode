class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;

        int row = 0;
        int col = m-1;

        int last_row = -1;
        int last_col = -1;

        while(1){
            if((row==last_row && col==last_col)||(row>=n||col<0))
                break;
            if(target==matrix[row][col]){
                break;
            }
            if(target<matrix[row][col]){
                last_row = row;
                last_col = col;
                col -= 1;
                continue;
            }
            if(target>matrix[row][col]){
                last_row = row;
                last_col = col;
                row += 1;
                continue;
            }
        }

        if(row<n&&col>=0){
            return true;
        }
        return false;
    }
};

// “倒逼”，反向的用大的边界去逼近真实值。如果正向的去逼近的话，向左向右都有可能，这样就没办法减小候选集合。
// 因此，若从右上角开始，每次右上角的值和target值的判断都能减去一行或一列，所以这样的缩减候选的方法是有效的。 

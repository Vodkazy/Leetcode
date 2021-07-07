class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0)return res;
        int row = matrix.size();
        int col = matrix[0].size();
        int idx = 0;
        int left=0,top=0,right=col-1,bottom=row-1;
        while(1){
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            if (++top > bottom) {
                break;
            }
            //从上往下走
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }
            //从右往左走
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            if (--bottom < top) {
                break;
            }
            //从下往上走
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return res;
    }
};

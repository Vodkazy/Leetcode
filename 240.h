class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = 0;
        int n = matrix[0].size()-1;

        while(m<matrix.size()&&n>=0){
            if(matrix[m][n]==target)break;
            if(matrix[m][n]>target){
                n--;
            }else{
                m++;
            }
        }
        
        if(m<matrix.size()&&n>=0)return true;
        return false;
    }
};

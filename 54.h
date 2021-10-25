class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;

        int l=0, r=n-1, t=0, b=m-1;

        int i=0,j=0;

        while(l<=r && t<=b){
            while(j<=r){
                res.push_back(matrix[i][j]);
                if(j!=r) j++;
                else break;
            }
            t++,i++;
            if(!(l<=r && t<=b))break;

            while(i<=b){
                res.push_back(matrix[i][j]);
                if(i!=b) i++;
                else break;
            }
            r--,j--;
            if(!(l<=r && t<=b))break;

            while(j>=l){
                res.push_back(matrix[i][j]);
                if(j!=l) j--;
                else break;
            }
            b--,i--;
            if(!(l<=r && t<=b))break;

            while(i>=t){
                res.push_back(matrix[i][j]);
                if(i!=t) i--;
                else break;
            }
            l++,j++;
            if(!(l<=r && t<=b))break;
        }
        return res;
    }
};

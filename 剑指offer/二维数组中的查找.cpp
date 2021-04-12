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

// �����ơ���������ô�ı߽�ȥ�ƽ���ʵֵ����������ȥ�ƽ��Ļ����������Ҷ��п��ܣ�������û�취��С��ѡ���ϡ�
// ��ˣ��������Ͻǿ�ʼ��ÿ�����Ͻǵ�ֵ��targetֵ���ж϶��ܼ�ȥһ�л�һ�У�����������������ѡ�ķ�������Ч�ġ� 

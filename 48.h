class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        map<pair<int,int>,int>m;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                pair<int,int> a = make_pair(i,j);
                if(m.find(a)!=m.end())continue;
                m[a]=1;
                
                int x = i;
                int y = j;
                int next_x = y;
                int next_y = n-1-x;

                int now = matrix[x][y];
                int tmp = matrix[next_x][next_y];
                matrix[next_x][next_y] = now;
                now = tmp;
                x = next_x, y = next_y;
                next_x = y, next_y = n-1-x;

                a = make_pair(x,y);
                if(m.find(a)!=m.end())continue;
                m[a]=1;

                tmp = matrix[next_x][next_y];
                matrix[next_x][next_y] = now;
                now = tmp;
                x = next_x, y = next_y;
                next_x = y, next_y = n-1-x;

                a = make_pair(x,y);
                if(m.find(a)!=m.end())continue;
                m[a]=1;

                tmp = matrix[next_x][next_y];
                matrix[next_x][next_y] = now;
                now = tmp;
                x = next_x, y = next_y;
                next_x = y, next_y = n-1-x;

                a = make_pair(x,y);
                if(m.find(a)!=m.end())continue;
                m[a]=1;

                matrix[next_x][next_y] = now;
            }
        }
    }
};

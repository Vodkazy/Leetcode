class Solution {
public:
    int vis[50005];
    vector<vector<int>>graph;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            vector<int> tmp;
            graph.push_back(tmp);
        }
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        memset(vis, 0, sizeof(vis));
        bool flag = true;
        for(int i=0;i<numCourses;i++){
            if(dfs(i)){
                flag = false;
                break;
            }
        }
        return flag;
    }

    bool dfs(int i){
        if(vis[i]==1)return true;
        if(vis[i]==2)return false;
        vis[i] = 1;
        for(int j=0;j<graph[i].size();j++){
            bool f = dfs(graph[i][j]);
            if(f)return true;
        }
        vis[i] = 2;
        return false;
    }

};

// ����������⣬����õ��ǽ�ͼ+dfs������в�����ͼ�޻�����ô�����������ͼ������ͼ��Ȼ�޻�����Ϊ��ͼ��ȥ�ı߶��������ˣ������ڱտڣ��� 

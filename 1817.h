class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> m;
        for(int i=0;i<logs.size();i++){
            m[logs[i][0]].insert(logs[i][1]);
        }
        vector<int>res;
        for(int i=0;i<k;i++)res.push_back(0);
        
        for(auto i=m.begin();i!=m.end();i++){
            res[(*i).second.size()-1] += 1;
        }
        
        return res;
    }
};

// ÊìÏ¤Ò»ÏÂSTL±éÀú 

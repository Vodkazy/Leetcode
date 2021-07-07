class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>>m;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if(m.count(strs[i])==0){
                vector<string> temp;
                m[strs[i]] = temp;
            }
            m[strs[i]].push_back(s);
        }
        for(auto k=m.begin();k!=m.end();k++){
            res.push_back(k->second);
        }
        return res;
    }
};

// 利用hash，hash相同值混入同一个桶 

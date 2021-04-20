class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>res;
        if(nums.size()<3)return res;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]] = 1;
            }
            else{
                m[nums[i]] += 1;
            }
        }
        for(int i=0;i<nums.size()-2;i++){
            if(m[nums[i]]==1)m.erase(nums[i]);
            else m[nums[i]]-=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==nums[j-1]&&j-1!=i)continue;
                if(m.find(-nums[i]-nums[j])!=m.end()){
                    if(((-nums[i]-nums[j])==nums[j] && m[nums[j]]<2)||((-nums[i]-nums[j]) < nums[j])){
                        continue;
                    }
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(-nums[i]-nums[j]);
                    sort(tmp.begin(), tmp.end());
                    s.insert(tmp);
                }
            }
        }
        for(auto i=s.begin();i!=s.end();i++){
            res.push_back(*i);
        }
        return res;
    }
};

// 相当于固定一个数，再转换成二数之和问题。排序+双指针/哈希表。 

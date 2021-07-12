class Solution {
public:
    static bool cmp (const vector<int> &a, const vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        else return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        int l = intervals[0][0];
        int r = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>r){
                vector<int>tmp;
                tmp.push_back(l);
                tmp.push_back(r);
                res.push_back(tmp);
                l = intervals[i][0];
                r = intervals[i][1];
            }else{
                r = max(r, intervals[i][1]);
            }
        }
        vector<int>tmp;
        tmp.push_back(l);
        tmp.push_back(r);
        res.push_back(tmp);
        return res;
    }
};

// 原来STL的cmp要求是静态函数.. 

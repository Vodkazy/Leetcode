class Solution {
public:

    string int2string(int num){
        string s = "";
        int n = num;
        if(n==0)return "0";
        while(n){
            char nn = n%10+'0';
            s = nn + s;
            n/=10;
        }
        return s;
    }

    struct cmp{
        bool operator()(string& a, string& b) {return a+b > b+a;}
    };

    string largestNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>0)break;
        }
        if(sum==0)return "0";
	    vector<string>s;
        for(int i=0;i<nums.size();i++)s.push_back(int2string(nums[i]));
        sort(s.begin(),s.end(),cmp());
        string res = "";
        for(auto iter=s.begin();iter!=s.end();iter++)res=res+(*iter);
        return res;
    }
};

// 自定义排序，string好难搞，只能强制静态 

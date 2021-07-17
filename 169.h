class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int now_num = nums[0];
        for(int i=1;i<nums.size();i++){
            if(now_num!=nums[i]){
                cnt--;
            }else{
                cnt++;
            }
            if(cnt<=0){
                now_num = nums[i+1];
                i++;
                cnt = 1;
            }
        }
        return now_num;
    }
};

// 美其名曰，摩尔投票法，就是不相同的就抵消，最后还剩下的数肯定就是多的数。 

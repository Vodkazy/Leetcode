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

// ������Ի��Ħ��ͶƱ�������ǲ���ͬ�ľ͵��������ʣ�µ����϶����Ƕ������ 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int n = nums.size();
        int maxn = nums[n-1];
        int max_pos = n-1;
        int pos = -1;
        for(int i=n-2;i>=0;i--){
            if(maxn>nums[i]){
                pos=i;
                break;
            }
            if(nums[i]>maxn){
                maxn = nums[i];
                max_pos = i;
            }
        }
        if(pos==-1){
            sort(nums.begin(), nums.end());
        }else{
            for(int i=n-1;i>pos;i--){
                if(nums[i]>nums[pos]&&nums[i]<maxn){
                    maxn = nums[i];
                    max_pos = i;
                }
            }
            swap(nums[max_pos], nums[pos]);
            sort(nums.begin()+pos+1, nums.end());
        }
        return;
    }
};

// 下一个全排列，核心思想是：找到比当前数刚刚好一点点的数
// 因为右边的改变是变化最小的，所以就希望从右边开始，找到可以变换的位置，这个位置满足，它的右边有比它大的数
// 如果有的话，在这个位置k右边，找到 最小的 比 nums[k]大的数，这个数就是k这个位置变换后应该出现的新数
// 剩下的就是相当于在右边这部分给它从小往大排序 

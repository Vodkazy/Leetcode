class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        int l = 0;
        int r = nums.size()-1;
        int index = -1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(nums[mid]==target){
                index = mid;
                break;
            }else if(nums[mid]>target){
                if(nums[mid]<nums[0]){
                    r = mid-1;
                }else{
                    if(target>=nums[0])r=mid-1;
                    else l=mid+1;
                }
            }else{
                if(nums[mid]>nums[nums.size()-1]){
                    l = mid+1;
                }else{
                    if(target<=nums[nums.size()-1])l=mid+1;
                    else r=mid-1;
                }
            }
        }
        if(index!=-1||nums[l]==target)return index;
        return -1;
    }
};

// 具有两部分单调性的二分...写的时候踩了太多坑..... 

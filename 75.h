class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int l = left, r = right;
        int value = nums[l];
        while(l<r){
            while(l<r&&nums[r]>=value)r--;
            nums[l]=nums[r];
            while(l<r&&nums[l]<=value)l++;
            nums[r]=nums[l];
        }
        nums[l] = value;
        return l;
    }

    void quickSort(vector<int>& nums, int l, int r){
        if(l>=r)return;
        int pos = partition(nums, l, r);
        quickSort(nums, l, pos-1);
        quickSort(nums, pos+1, r);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
    }
};

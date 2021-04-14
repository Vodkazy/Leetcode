class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right){
        if(left<0||left>=nums.size()||right<0||right>=nums.size()||left>right)return;
        int l = left;
        int r = right;
        int index = left;
        int sp = nums[l];
        while(l<r){
            while(l<r && nums[r]<=sp){
                r--;
            }
            if(l<r){
                nums[l] = nums[r];
                l++;
            }
            while(l<r && nums[l]>sp){
                l++;
            }
            if(l<r){
                nums[r] = nums[l];
                r--;
            }
        }
        nums[l]=sp;
        quickSort(nums,left,l-1);
        quickSort(nums,l+1,right);
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        return nums[k-1];
    }
};

// 手撸快速排序，双指针滑动窗口 + 递归分治（给某数找位置，使其左边都大，右边都小）。上次排好序之后再递归下层。 
// 优先队列，priority_queue<int, vector<int>, greater<int>>最小堆
// 快排的非递归方法，把原来的递归改成入栈，站内每个元素都是待排序的子区间<start,end>， 当栈不为空时一直分治。 
// 第K大的非递归的方法，不断快排获得当前位置左边还有几个比它大的数，然后相应的调整窗口，直至排序完的子区间左边只有K-1个比它大 

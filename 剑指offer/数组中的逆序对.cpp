class Solution {
public:
    int ans = 0;

    void gSort(vector<int>& nums1, int l, int r){
        if(l>=r)return;
        int mid = (l+r)>>1;
        gSort(nums1, l, mid);
        gSort(nums1, mid+1, r);
        gMerge(nums1, l, mid, r);
    }

    void gMerge(vector<int>& nums1, int left, int mid, int right){
        vector<int>temp;
        int l1=left, l2=mid+1;
        while(l1<=mid && l2<=right){
            if(nums1[l1]<=nums1[l2]) temp.push_back(nums1[l1++]);
            else ans+=(mid-l1+1), temp.push_back(nums1[l2++]);
        }
        while(l1<=mid)temp.push_back(nums1[l1++]);
        while(l2<=right)temp.push_back(nums1[l2++]);
        for(int i=0;i<temp.size();i++){
            nums1[left+i] = temp[i];
        }
    }

    int reversePairs(vector<int>& nums) {
        gSort(nums, 0, nums.size()-1);
        return ans;
    }
};

// 标准的归并排序，只需要在左半边的数比右半边的数大的时候，把左半边剩下的必然比右半边大的数的个数加进去即可。 

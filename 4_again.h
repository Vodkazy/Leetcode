class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=0, r=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>res;
        while(l<m && r<n){
            if(nums1[l]<nums2[r]){
                res.push_back(nums1[l]);
                l++;
            }else{
                res.push_back(nums2[r]);
                r++;
            }
        }
        while(l!=nums1.size())res.push_back(nums1[l++]);
        while(r!=nums2.size())res.push_back(nums2[r++]);
        int mid = (m+n)>>1;
        if((m+n)%2==0){
            return (res[mid]*1.0 + res[mid-1]*1.0)/2.0;
        }else{
            return res[mid]*1.0;
        }
        return 0.0;
    }
}; // O(N^2),直接双指针归并排序 

class Solution {
public:
    // 每次确定k/2个，即8->4->2->1
    double findTopK(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        int l1=0, l2=0;
        double res = 0;
        while(1){
            if(l1==m){
                res = nums2[l2+k-1];
                break;
            }
            if(l2==n){
                res = nums1[l1+k-1];
                break;
            }
            if(k==1){
                res = min(nums1[l1], nums2[l2]);
                break;
            }
            int r1 = min(m-1, l1 + k/2 -1);
            int r2 = min(n-1, l2 + k/2 -1);
            if(nums1[r1]<nums2[r2]){
                k -= (r1-l1+1);
                l1 = r1+1;
            }else{
                k -= (r2-l2+1);
                l2 = r2+1;
            }
        }
        return res;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m+n+1)>>1;
        if((m+n)%2!=0){
            return findTopK(nums1, nums2, k);
        }else{
            return (findTopK(nums1, nums2, k) + findTopK(nums1, nums2, k+1))/2;
        }
        return 0;
    }
}; 
// O(NlogN)，等价于两个有序数组找第K小。还是双指针，两个数组同时双指针，本应该是四指针，但是右边界都是固定长度，两个数组都是同步的长度为k/2，也就是右边界可以通过左边界计算出来，所以实际上是二分
// 要寻找k小，也就是去同时比较两边k/2的数组，如果nums1[k/2]比nums2[k/2]小，那么一定可以确定的是 nums1的前k/2个一定是包含在k里面的
// 然后下一次循环相当于就找剩下的k/2个数，也就是新一轮的第K小，那么区间长度就变成了两个数组分别k/4长度..如此一直二分，直到区间长度为1
// 注意极端情况，比如一方先遍历到头了，比如长度为1 

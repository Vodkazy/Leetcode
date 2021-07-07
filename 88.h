class Solution {
public:
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
            else temp.push_back(nums1[l2++]);
        }
        while(l1<=mid)temp.push_back(nums1[l1++]);
        while(l2<=right)temp.push_back(nums1[l2++]);
        for(int i=0;i<temp.size();i++){
            nums1[left+i] = temp[i];
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i=0;i<n;i++)nums1[m+i]=nums2[i];

        gSort(nums1, 0, m+n-1);

    }
};

// Á·Ï°¹é²¢ÅÅÐò 

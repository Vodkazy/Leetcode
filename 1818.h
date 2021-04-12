class Solution {
public:
    #define ll long long
    ll binary_search(int nums1[], int target, ll n){
        ll l = 0;
        ll r = n-1;
        while(l<r){
            ll mid = (l+r)/2;
            if(nums1[mid]==target){
                l=mid;
                break;
            }
            else if(nums1[mid]>target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        ll ans = 0;
        ll res = 999999;
        // cout << target << " " << nums1[l-1] << " " << nums1[l] << " " << nums1[l+1] <<endl;
        if(l-1>=0&&abs(nums1[l-1]-target)<res)res=abs(nums1[l-1]-target),ans=nums1[l-1];
        if(l+1<n&&abs(nums1[l+1]-target)<res)res=abs(nums1[l+1]-target),ans=nums1[l+1];
        if(l>=0&&l<n&&abs(nums1[l]-target)<res)res=abs(nums1[l]-target),ans=nums1[l];
        return ans;
    }
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        ll res = 0;
        ll minn = 0;
        for(int i=0;i<nums1.size();i++)res=(res+abs(nums1[i]-nums2[i]));
        int a[100005];
        for(int i=0;i<nums1.size();i++)a[i]=nums1[i];
        sort(a, a+nums1.size());
        minn = res;
        for(int i=0;i<nums1.size();i++){
            ll repla = binary_search(a, nums2[i], nums1.size());
            minn = min(minn, res-abs(nums2[i]-nums1[i])+abs(nums2[i]-repla));
        }
        return minn%1000000007;
    }
};


// 看清题目是只可以最多换一个元素，相当于遍历一遍nums1，看nums1[i]替换成nums1中的其他的哪个最好，肯定是选和nums2[i]最接近的
// 如果直接循环是O(N^2)会爆掉，所以O(NlogN)，显然要二分
// 肯定是根据nums2[i]当作target，所以对nums1排序然后二分找和它最接近的 

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


// ������Ŀ��ֻ������໻һ��Ԫ�أ��൱�ڱ���һ��nums1����nums1[i]�滻��nums1�е��������ĸ���ã��϶���ѡ��nums2[i]��ӽ���
// ���ֱ��ѭ����O(N^2)�ᱬ��������O(NlogN)����ȻҪ����
// �϶��Ǹ���nums2[i]����target�����Զ�nums1����Ȼ������Һ�����ӽ��� 

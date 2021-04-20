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
}; // O(N^2),ֱ��˫ָ��鲢���� 

class Solution {
public:
    // ÿ��ȷ��k/2������8->4->2->1
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
// O(NlogN)���ȼ����������������ҵ�KС������˫ָ�룬��������ͬʱ˫ָ�룬��Ӧ������ָ�룬�����ұ߽綼�ǹ̶����ȣ��������鶼��ͬ���ĳ���Ϊk/2��Ҳ�����ұ߽����ͨ����߽�������������ʵ�����Ƕ���
// ҪѰ��kС��Ҳ����ȥͬʱ�Ƚ�����k/2�����飬���nums1[k/2]��nums2[k/2]С����ôһ������ȷ������ nums1��ǰk/2��һ���ǰ�����k�����
// Ȼ����һ��ѭ���൱�ھ���ʣ�µ�k/2������Ҳ������һ�ֵĵ�KС����ô���䳤�Ⱦͱ������������ֱ�k/4����..���һֱ���֣�ֱ�����䳤��Ϊ1
// ע�⼫�����������һ���ȱ�����ͷ�ˣ����糤��Ϊ1 

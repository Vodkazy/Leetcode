#include <bits/stdc++.h>

using namespace std;

/*
   @ 编写Solution :  4.h
   @ 主函数入口    :  main.cpp
   @ Author      :  Vodka
   @ Time        :  19-9-21 下午1:57 
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int target ;
        double res;
        if((nums1.size()+nums2.size())%2==0) {
            target = (nums1.size() + nums2.size()) / 2;
            res = (binary_kth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), target)
                    + binary_kth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), target+1))/2;
//            cout << binary_kth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), target) <<endl;
//            cout << binary_kth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), target+1) <<endl;
        }
        else {
            target = (nums1.size() + nums2.size() +1 ) / 2;
            res = binary_kth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), target); //左闭右开
        }
        return res;
    }
    double binary_kth(vector<int>& nums1, vector<int>& nums2, int al, int ar, int bl, int br, int target){
//        cout<<al <<" "<< ar <<" "<< bl <<" "<<br<<endl;
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (al>=size1){
            return nums2[min(size2-1 ,bl + target -1)];
        }
        if (bl>=size2){
            return nums1[min(size1-1 ,al + target -1)];
        }
        if (target == 1){
            return min(nums1[min(size1-1,al)],nums2[min(size2-1,bl)]);
        }
        int pos_a_mid = int(min(max(0,al + target/2 -1), size1-1)); // 因为是坐标可取到，直接-1
        int pos_b_mid = int(min(max(0,bl + target/2 -1), size2-1));
        int a_mid = nums1[pos_a_mid];
        int b_mid = nums2[pos_b_mid];
        if(a_mid < b_mid){
//            cout<<"放入a"<<al <<"到a"<<pos_a_mid<<endl;
            return binary_kth(nums1, nums2, pos_a_mid + 1, ar, bl, br, target - (pos_a_mid + 1 - al));
        }
        else{
//            cout<<"放入b"<<bl <<"到b"<<pos_b_mid<<endl;
            return binary_kth(nums1, nums2, al, ar, pos_b_mid + 1, br, target - (pos_b_mid + 1 - bl)); //bl~bk/2 一定包含
        }
    }
};


/*  解决思路 & 复杂度
    一开始上来的想法是一个归并排序的问题，两个数组合到一起然后取a[(m+n)/2]。但是时间复杂度好像不太对。
    看见时间要求log，进而想到递归的办法。找到中位数，实际上就等价于在m+n个数中找到第(m+n)/2个数，
    鉴于题目中说明了数组已经排好序了，那么假设现在有两个数组，长度分别是m和n，分别都取前(m+n)/4个数，
    那么可以肯定的是，如果数组a的第(m+n)/4个数小于数组b的第(m+n)/4个数，那么数组a的前(m+n)/4个数就肯定是所有数中的前(m+n)/2中的数。
    那么问题就转化为，一开始是在a[0,m]和b[0,n]中找第(m+n)/2个数，现在拿出来了第(m+n)/4，就是在a[(m+n)/4+1,m]和b[0,n]中找其中的第(m+n)/4个数，
    进而又产生了与上一步相似的问题形式，所以可以通过递归进行求解即可。
    需要注意的一点是，每次target的减少量不能用target/2来表示，因为可能会存在“a数组剩下的元素不足target/2，但是都可以加进去”的情况，因此我直接采用了`target-(pos_a_mid+1-al)`来表示。
    另外下标的+1还是-1，包含还是不包含，左闭右开还是左闭右闭，整个代码都要保持一致。
    时间复杂度 O(log(m+n))
*/

/*  Main函数入口
    int main() {
        Solution ans = Solution();
        vector<int> nums1 = {1};
        vector<int> nums2 = {2,3,4,5,6};
    //  vector<int> nums1 = {1,2,3,5};
    //  vector<int> nums2 = {2};
        cout<< ans.findMedianSortedArrays(nums1,nums2)<<endl;
        return 0;
    }
*/

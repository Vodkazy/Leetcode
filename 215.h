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

// ��ߣ��������˫ָ�뻬������ + �ݹ���Σ���ĳ����λ�ã�ʹ����߶����ұ߶�С�����ϴ��ź���֮���ٵݹ��²㡣 
// ���ȶ��У�priority_queue<int, vector<int>, greater<int>>��С��
// ���ŵķǵݹ鷽������ԭ���ĵݹ�ĳ���ջ��վ��ÿ��Ԫ�ض��Ǵ������������<start,end>�� ��ջ��Ϊ��ʱһֱ���Ρ� 
// ��K��ķǵݹ�ķ��������Ͽ��Ż�õ�ǰλ����߻��м��������������Ȼ����Ӧ�ĵ������ڣ�ֱ������������������ֻ��K-1�������� 

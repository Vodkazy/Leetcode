class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int n = nums.size();
        int maxn = nums[n-1];
        int max_pos = n-1;
        int pos = -1;
        for(int i=n-2;i>=0;i--){
            if(maxn>nums[i]){
                pos=i;
                break;
            }
            if(nums[i]>maxn){
                maxn = nums[i];
                max_pos = i;
            }
        }
        if(pos==-1){
            sort(nums.begin(), nums.end());
        }else{
            for(int i=n-1;i>pos;i--){
                if(nums[i]>nums[pos]&&nums[i]<maxn){
                    maxn = nums[i];
                    max_pos = i;
                }
            }
            swap(nums[max_pos], nums[pos]);
            sort(nums.begin()+pos+1, nums.end());
        }
        return;
    }
};

// ��һ��ȫ���У�����˼���ǣ��ҵ��ȵ�ǰ���ոպ�һ������
// ��Ϊ�ұߵĸı��Ǳ仯��С�ģ����Ծ�ϣ�����ұ߿�ʼ���ҵ����Ա任��λ�ã����λ�����㣬�����ұ��б��������
// ����еĻ��������λ��k�ұߣ��ҵ� ��С�� �� nums[k]����������������k���λ�ñ任��Ӧ�ó��ֵ�����
// ʣ�µľ����൱�����ұ��ⲿ�ָ�����С�������� 

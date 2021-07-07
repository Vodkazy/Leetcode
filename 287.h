class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow=0,fast=0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

    }
};

// ������1~n����i��nums[i]֮�佨�ߵĻ�����Ȼ��һ��nums[i]���������ߣ��γ�һ���� ��N���㣬N+1���ߣ��ɲ����л��� 
// ������������Ǹ�i=nums[i]����Ϊ�����Ļ�û�а취��������ջ���û����ڣ�����������뻷�Ļ���һ�������ظ��ġ���Ϊi��0~n��nums[i]��1~n��
// Floyd ��Ȧ�㷨��
// ˫ָ�룬��һ��һ���ߣ��������ߣ�slow=nums[slow]��ʾһ��
// һ��ʼ����1��2����һ�ֿ϶��������������Կ�϶����뻷���������������϶��ڻ�������
// �ڶ��ֿ�ʼ��������0��Ҳ��ʼ�ڻ����ߣ���1��1��������ʱΪ�⡣����Ϊɶ����ʽ�Ƶ���

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        dq.push_back(0); //ע������Push����index����Ϊ�˼�¼���ֵ�Ƿ��Ѿ���������
        for(int i=1;i<k;i++){
            while(!dq.empty()&&nums[i]>=nums[dq.back()])dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i=k;i<nums.size();i++){
            // ÿ��ɾ���ȵ�ǰֵС�ģ���Ϊ��Щ��Ȼ�ò���
            while(!dq.empty()&&nums[i]>=nums[dq.back()])dq.pop_back();
            dq.push_back(i);
            // �����ǰ���ֵ�Ѿ������ˣ���pop
            while(i-(dq.front())+1>k)dq.pop_front();
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

// ��ϰʹ��deque��˫����С�front(),back(),pop_front(),pop_back()

// �����ǣ������ڱȵ�ǰֵС�Ķ�û�ã�ֻ�бȵ�ǰֵ�����ڴ����ڵĲ����á� 

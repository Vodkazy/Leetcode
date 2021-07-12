class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)return 0;
        int left[30005], right[30005];
        int maxn = height[0];
        for(int i=0;i<height.size();i++){
            left[i]=maxn;
            if(height[i]>maxn)maxn=height[i];
        }
        maxn = height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            right[i]=maxn;
            if(height[i]>maxn)maxn=height[i];
        }
        int sum = 0;
        for(int i=1;i<height.size();i++){
            int h = min(left[i], right[i]);
            if(h>=height[i]){
                sum+=(h-height[i]);
            }
        }
        return sum;
    }
};

// ��Ȼ��hard��...���ܱȽ��ѵ���˼·��ÿ��λ���ܳ˶���ˮ���������߱����ߵľ����ģ���������С������ˮλӦ���������������ߵ�����������
// ���Զ���ÿ��λ�ã�ͳ������ߺ��ұߵ����ֵ�������Ϳ����γ�һ��С�������������������ˮλ�ɶ����еĶ̰������ÿ��λ�õ�ˮλ����ˮλ-��ǰλ�ø߶Ⱦ����� 

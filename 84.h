class Solution {
public:
    struct cmp{
        bool operator () (pair<int,int>& a, pair<int,int>& b){
            return a.second<b.second;
        }
    };

    int left_len[300005];
    int right_len[300005];

    int largestRectangleArea(vector<int>& heights) {

        memset(left_len, 0, sizeof(left_len));

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        
        int now_have = 0;
        for(int i=0;i<heights.size();i++){
            int cnt = 0;
            int cnt_cli = 0;
            while(!pq.empty()){
                pair<int,int> top = pq.top();
                if(top.second > heights[i]){
                    left_len[top.first] = i;
                    pq.pop();
                }else{
                    break;
                }
            }
            pq.push(make_pair(i,heights[i]));
        }
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            left_len[top.first] = heights.size();
            pq.pop();
        }
            
        for(int i=heights.size()-1;i>=0;i--){
            while(!pq.empty()){
                pair<int,int> top = pq.top();
                if(top.second>heights[i]){
                    right_len[top.first] = i;
                    pq.pop();
                }else{
                    break;
                }
            }
            pq.push(make_pair(i,heights[i]));
        }
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            right_len[top.first] = -1;
            pq.pop();
        }

        // for(int i=0;i<heights.size();i++){
        //     cout<<left_len[i]<<" "<<right_len[i]<<endl;
        // }

        int maxn = 0;

        for(int i=0;i<heights.size();i++){
            maxn = max(maxn, heights[i]*(left_len[i]-right_len[i]-1));
        }

        return maxn;
    }
};

// hard�⣬��height[i]Ϊ�߶ȵĳ����ε����ұ߽磬�ǵ�һ��С��height[i]��ֵ������ֻ��ҪΪÿ��height[i]�ֱ�����ߺ��ұߵ�һ������С��λ�ü��ɡ�
// ����ֱ��N^2��ÿ��height[i]������ָ�����ߣ�T��
// �����ÿռ任ʱ�䣬�ȴ������ң�ά��һ��pair<index, value>�����ȶ��У��������Ԫ�رȵ�ǰҪ��ӵĴ���ô���׳��У��ö��׶�Ӧ��λ�õ�Ԫ�ص��ұ߽���ǵ�ǰҪ���Ԫ�ص�λ��
// ��������ɨ���ߣ������ÿ��λ�õı߽磬�ٺ�height[i]�����˷��Ϳ����ˡ�	 

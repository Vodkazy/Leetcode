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

// hard题，以height[i]为高度的长方形的左右边界，是第一个小于height[i]的值，所以只需要为每个height[i]分别找左边和右边第一个比它小的位置即可。
// 上来直接N^2，每个height[i]用左右指针来走，T了
// 后来用空间换时间，先从左向右，维护一个pair<index, value>的优先队列，如果队首元素比当前要入队的大，那么队首出列，该队首对应的位置的元素的右边界就是当前要入队元素的位置
// 这样左右扫两边，求出来每个位置的边界，再和height[i]做个乘法就可以了。	 

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

// 竟然是hard题...可能比较难的是思路。每个位置能乘多少水是由它两边比它高的决定的，并且整个小分区的水位应该是由这个分区最高的两个决定，
// 所以对于每个位置，统计它左边和右边的最大值，这样就可以形成一个小堰塞湖，堰塞湖的最高水位由二者中的短板决定，每个位置的水位由总水位-当前位置高度决定。 

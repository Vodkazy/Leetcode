class Solution {
public:
    int maxArea(vector<int>& height) {
		int l=0,r=height.size()-1;
		int area = min(height[l],height[r])*(r-l);
		while(l<r){
			int h = min(height[l], height[r]);
			int w = r-l;
			int now_area = h*w;
			
			if(now_area>area){
				area = now_area;
			}
			
			if(height[l]>height[r]){
				r--;
			}else{
				l++;
			}
			
		}
		return area;
    }
};

// 滑动窗口，一端在左，一端在右 

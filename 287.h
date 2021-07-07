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

// 数都在1~n，在i与nums[i]之间建边的话，必然有一个nums[i]被连两条边，形成一个环 （N个点，N+1条边，可不得有环吗） 
// 这个环不可能是个i=nums[i]，因为这样的话没有办法进入这个闭环，没有入口，所以如果进入环的话，一定是有重复的。因为i是0~n，nums[i]是1~n。
// Floyd 判圈算法：
// 双指针，慢一步一步走，快两步走，slow=nums[slow]表示一步
// 一开始，慢1快2，第一轮肯定不会相遇，所以快肯定进入环。当二者相遇，肯定在环内相遇
// 第二轮开始，把慢归0，也开始在环里走，慢1快1，再相遇时为解。具体为啥看公式推导。

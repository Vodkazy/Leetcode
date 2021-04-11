class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 最小值
        int l = 0;
        int r = numbers.size()-1;

        while(l<=r){
            //cout<<l<<" "<<r<<endl;
            int mid = l+(r-l)/2;
            if(numbers[mid]==numbers[r]){
                r--;
            }
            else if(numbers[mid]<numbers[r]){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return numbers[l];
    }
};

# 最简单的做法就是直接输出最小值，这里利用二分来利用分段有序的性质来做 
# 我们实际上希望找到的就是一个值，这个值比它左边的值小，并且比右边的值也小。或者直接是最右边的值。极端情况就是全都相等。 
# 二分，target为符合这一性质的值。 

# 寻找某 一个数 
# 因为我们初始化 right = nums.length - 1
# 所以决定了我们的「搜索区间」是 [left, right]
# 所以决定了 while (left <= right)
# 同时也决定了 left = mid+1 和 right = mid-1
# 因为我们只需找到一个 target 的索引即可
# 所以当 nums[mid] == target 时可以立即返回
# int binarySearch(int[] nums, int target) {
#    int left = 0, right = nums.size()-1;
#    while(left<=right) { //因为是[]都是闭区间，所以<= 
#        int mid = left + (right - left) / 2;
#        if (nums[mid] == target) {
#            return target
#        } else if (nums[mid] < target) {
#            left = ... mid+1 //因为比较数的话，当前的值不等于target那肯定就把mid排除在外了 
#        } else if (nums[mid] > target) {
#            right = ... mid-1
#        }
#    }
#    return -1;
# }

# 寻找某 左侧边界
# 因为我们初始化 right = nums.length
# 所以决定了我们的「搜索区间」是 [left, right)
# 所以决定了 while (left < right)
# 同时也决定了 left = mid+1 和 right = mid
# 因为我们需找到 target 的最左侧索引
# 所以当 nums[mid] == target 时不要立即返回
# 而要收紧右侧边界以锁定左侧边界
# int binarySearch(int[] nums, int target) {
#    int left = 0, right = nums.size();
#    while(left<right) {
#        int mid = left + (right - left) / 2;
#        if (nums[mid] == target) {
#            right = mid //因为左侧的边界一定比target小，所以right移动 
#        } else if (nums[mid] < target) {
#            left = ... mid+1  //因为mid有可能成为边界，所以不能把mid包含起来 
#        } else if (nums[mid] > target) {
#            right = ... mid //因为mid肯定不在target里，所以mid和一开始right取size()保持一致，使用开区间 
#        }
#		 // 因为我们的「搜索区间」是 [left, right) 左闭右开，所以当 nums[mid] 被检测之后，下一步的搜索区间应该去掉 mid 分割成两个区间，即 [left, mid) 或 [mid + 1, right)。 
#    }
#    return right;
# }

# 寻找某 右侧边界
# 因为我们初始化 right = nums.length
# 所以决定了我们的「搜索区间」是 [left, right)
# 所以决定了 while (left < right)
# 同时也决定了 left = mid+1 和 right = mid
# 因 为我们需找到 target 的最右侧索引
# 所以当 nums[mid] == target 时不要立即返回
# 而要收紧左侧边界以锁定右侧边界
# 又因为收紧左侧边界时必须 left = mid + 1
# 所以最后无论返回 left 还是 right，必须减一
# int binarySearch(int[] nums, int target) {
#    int left = 0, right = nums.size();
#    while(left<right) {
#        int mid = left + (right - left) / 2;
#        if (nums[mid] == target) {
#            left = mid+1 //因为mid肯定不在下一次的搜索范围里，所以mid和一开始left取闭区间保持一致，取下一个搜索空间左边的闭区间 
#        } else if (nums[mid] < target) {
#            left = ... mid+1  //因为mid肯定不在下一次搜索范围里，同上 
#        } else if (nums[mid] > target) {
#            right = ... mid //因为mid肯定不在下一次的搜索范围里，所以mid和一开始right取size()保持一致，使用开区间 
#        }
#    }
#    return left-1;
# }

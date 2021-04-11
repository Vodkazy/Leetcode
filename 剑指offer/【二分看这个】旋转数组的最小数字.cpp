class Solution {
public:
    int minArray(vector<int>& numbers) {
        // ��Сֵ
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

# ��򵥵���������ֱ�������Сֵ���������ö��������÷ֶ�������������� 
# ����ʵ����ϣ���ҵ��ľ���һ��ֵ�����ֵ������ߵ�ֵС�����ұ��ұߵ�ֵҲС������ֱ�������ұߵ�ֵ�������������ȫ����ȡ� 
# ���֣�targetΪ������һ���ʵ�ֵ�� 

# Ѱ��ĳ һ���� 
# ��Ϊ���ǳ�ʼ�� right = nums.length - 1
# ���Ծ��������ǵġ��������䡹�� [left, right]
# ���Ծ����� while (left <= right)
# ͬʱҲ������ left = mid+1 �� right = mid-1
# ��Ϊ����ֻ���ҵ�һ�� target ����������
# ���Ե� nums[mid] == target ʱ������������
# int binarySearch(int[] nums, int target) {
#    int left = 0, right = nums.size()-1;
#    while(left<=right) { //��Ϊ��[]���Ǳ����䣬����<= 
#        int mid = left + (right - left) / 2;
#        if (nums[mid] == target) {
#            return target
#        } else if (nums[mid] < target) {
#            left = ... mid+1 //��Ϊ�Ƚ����Ļ�����ǰ��ֵ������target�ǿ϶��Ͱ�mid�ų������� 
#        } else if (nums[mid] > target) {
#            right = ... mid-1
#        }
#    }
#    return -1;
# }

# Ѱ��ĳ ���߽�
# ��Ϊ���ǳ�ʼ�� right = nums.length
# ���Ծ��������ǵġ��������䡹�� [left, right)
# ���Ծ����� while (left < right)
# ͬʱҲ������ left = mid+1 �� right = mid
# ��Ϊ�������ҵ� target �����������
# ���Ե� nums[mid] == target ʱ��Ҫ��������
# ��Ҫ�ս��Ҳ�߽����������߽�
# int binarySearch(int[] nums, int target) {
#    int left = 0, right = nums.size();
#    while(left<right) {
#        int mid = left + (right - left) / 2;
#        if (nums[mid] == target) {
#            right = mid //��Ϊ���ı߽�һ����targetС������right�ƶ� 
#        } else if (nums[mid] < target) {
#            left = ... mid+1  //��Ϊmid�п��ܳ�Ϊ�߽磬���Բ��ܰ�mid�������� 
#        } else if (nums[mid] > target) {
#            right = ... mid //��Ϊmid�϶�����target�����mid��һ��ʼrightȡsize()����һ�£�ʹ�ÿ����� 
#        }
#		 // ��Ϊ���ǵġ��������䡹�� [left, right) ����ҿ������Ե� nums[mid] �����֮����һ������������Ӧ��ȥ�� mid �ָ���������䣬�� [left, mid) �� [mid + 1, right)�� 
#    }
#    return right;
# }

# Ѱ��ĳ �Ҳ�߽�
# ��Ϊ���ǳ�ʼ�� right = nums.length
# ���Ծ��������ǵġ��������䡹�� [left, right)
# ���Ծ����� while (left < right)
# ͬʱҲ������ left = mid+1 �� right = mid
# �� Ϊ�������ҵ� target �����Ҳ�����
# ���Ե� nums[mid] == target ʱ��Ҫ��������
# ��Ҫ�ս����߽��������Ҳ�߽�
# ����Ϊ�ս����߽�ʱ���� left = mid + 1
# ����������۷��� left ���� right�������һ
# int binarySearch(int[] nums, int target) {
#    int left = 0, right = nums.size();
#    while(left<right) {
#        int mid = left + (right - left) / 2;
#        if (nums[mid] == target) {
#            left = mid+1 //��Ϊmid�϶�������һ�ε�������Χ�����mid��һ��ʼleftȡ�����䱣��һ�£�ȡ��һ�������ռ���ߵı����� 
#        } else if (nums[mid] < target) {
#            left = ... mid+1  //��Ϊmid�϶�������һ��������Χ�ͬ�� 
#        } else if (nums[mid] > target) {
#            right = ... mid //��Ϊmid�϶�������һ�ε�������Χ�����mid��һ��ʼrightȡsize()����һ�£�ʹ�ÿ����� 
#        }
#    }
#    return left-1;
# }

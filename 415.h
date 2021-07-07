class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();

        int jinwei = 0;
        string s = "";

        int i = 1;
        int j = 1;
        while(m-i>=0||n-j>=0){
            char now_nums1 = '0';
            char now_nums2 = '0';
            if(m-i>=0)now_nums1=num1[m-i];
            if(n-j>=0)now_nums2=num2[n-j];
            char temp = now_nums1-'0'+now_nums2+jinwei;
            if(temp>'9')temp-=10;
            s = temp + s;
            jinwei = ((now_nums1-'0') + (now_nums2-'0') + jinwei) /10 ;
            i++,j++;
        }
        if(jinwei>0)s = '1'+s;
        return s;
    }
};

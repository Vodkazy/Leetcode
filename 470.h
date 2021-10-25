// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true) {
            int num = (rand7()-1)*7 + rand7(); // rand 49
            if(num <= 40) return num % 10 + 1; // 拒绝采样
            
            a = num - 40; // rand 9
            b = rand7();
            num = (a-1)*7 + b; // rand 63
            if(num <= 60) return num % 10 + 1;
            
            a = num - 60; // rand 3
            b = rand7();
            num = (a-1)*7 + b; // rand 21
            if(num <= 20) return num % 10 + 1;
        }
    }
};

// 第一次见这种题。。实际上要做的就是做到均匀采样。用(rand()-1)*n+rand()去做randN，然后如果在某个阈值下均匀，就可以做到rand阈值
// 其实用RAND10就能出来RAND7，因为均匀，只需要>7继续rand就好 

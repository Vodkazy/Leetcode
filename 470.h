// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true) {
            int num = (rand7()-1)*7 + rand7(); // rand 49
            if(num <= 40) return num % 10 + 1; // �ܾ�����
            
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

// ��һ�μ������⡣��ʵ����Ҫ���ľ����������Ȳ�������(rand()-1)*n+rand()ȥ��randN��Ȼ�������ĳ����ֵ�¾��ȣ��Ϳ�������rand��ֵ
// ��ʵ��RAND10���ܳ���RAND7����Ϊ���ȣ�ֻ��Ҫ>7����rand�ͺ� 

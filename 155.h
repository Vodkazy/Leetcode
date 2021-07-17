class MinStack {
    stack<pair<int,int>> s;
public:
    MinStack() {
        while(!s.empty())s.pop();
        s.push(make_pair(0,INT_MAX));
    }
    
    void push(int x) {
        if(s.empty())s.push(make_pair(x, x));
        s.push(make_pair(x, min(x, s.top().second)));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

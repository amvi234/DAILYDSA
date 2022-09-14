#include<stack>
class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    int top1=-1;
    int top2=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
       while(!s1.empty()){
            s2.push(s1.top());
           s1.pop();
       }
        s2.push(x);
         while(!s2.empty()){
            s1.push(s2.top());
           s2.pop();
       }
        }
        
    
    
    int pop() {
       int curr = s1.top();
        s1.pop();
        return curr;
    }
    
    int peek() {
        int b = s1.top();
        return b;
    }
    
    bool empty() {
        if(s1.empty()){
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
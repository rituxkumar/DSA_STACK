class MyQueue {
public:
    stack<int> s1; //  stack (push here)
    stack<int> s2; //   stack (pop/peek from here)

    MyQueue() {}

    // push new element to the back of queue
    void push(int x) { s1.push(x); }

    // pop from front of queue
    int pop() {
        if (s2.empty())
            transferS1toS2();
        int val = s2.top();
        s2.pop();
        return val; 
    }

    // get front element
    int peek() {
        if (s2.empty())
            transferS1toS2();
        if (s2.empty())
            return -1; 
        return s2.top();
    }

    bool empty() { return s1.empty() && s2.empty(); }

private:
    
    void transferS1toS2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};
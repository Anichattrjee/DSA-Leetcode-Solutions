class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);

        for(int i=0;i<size;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topel=q.front();
        q.pop();
        return topel;

    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        int size=q.size();
        if(size==0)return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
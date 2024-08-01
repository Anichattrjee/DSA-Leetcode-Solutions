
class MinStack {
public:
    std::stack<long long> st;
    long long min = LLONG_MAX; // Use LLONG_MAX for initialization

    MinStack() {
    }
    
    void push(int val) {
        long long value = static_cast<long long>(val); // Cast val to long long
        if (st.empty()) {
            st.push(value);
            min = value;
        } else {
            if (value < min) {
                st.push(2 * value - min); // Ensure this calculation uses long long
                min = value;
            } else {
                st.push(value);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < min) {
            min = 2 * min - x; // Ensure this calculation uses long long
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        long long x = st.top();
        if (x < min) return static_cast<int>(min); // Cast min to int
        return static_cast<int>(x); // Cast x to int
    }
    
    int getMin() {
        return static_cast<int>(min); // Cast min to int
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

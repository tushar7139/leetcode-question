class MinStack {
private:
    int min_ele;
    stack<long long>st;
public:
    MinStack() {
        min_ele=-1;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min_ele=val;
        }else{
            if(val>=min_ele){
                st.push(val);
            }else{
                st.push(2*1LL*val-min_ele);
                min_ele=val;
            }
        }
    }
    
    void pop() {                                  
        if(st.top()>=min_ele){
            st.pop();
        }else{
            min_ele=2*1LL*min_ele-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>=min_ele){
            return st.top();
        }else{
            return min_ele;
        }
    }
    
    int getMin() {
        return min_ele;
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
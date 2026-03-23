#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minEle;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            minEle = val;
            st.push(val);
        }
        else{
            if(val > minEle){
                st.push(val);
            }
            else{
                st.push(2LL*val-minEle);
                minEle = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long x = st.top();
        st.pop();
        if(x < minEle){
            minEle = 2LL*minEle-x;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long x = st.top();
        if(minEle < x){
            return x;
        }
        return (int)minEle;
    }
    
    int getMin() {
        return (int)minEle;
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
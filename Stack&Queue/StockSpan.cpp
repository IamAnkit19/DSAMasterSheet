#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    vector<int> stock;
    stack<int> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && stock[st.top()] <= price){
            st.pop();
        }
        int count = stock.size() - (st.empty() ? -1 : st.top());
        st.push(stock.size());
        stock.push_back(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
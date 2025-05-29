// version1: monotonic stack
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int answer=1;
        while(!st.empty() && st.top().first <= price) {
            answer+=st.top().second;
            st.pop();
        }
        st.push(pair<int,int>(price, answer));
        return answer;
    }
};

// version2: no stack
class StockSpanner {
public:
    vector<int> stock;
    vector<int> span;
    StockSpanner() {}
    
    int next(int price) {
        int s=1;
        int idx=span.size()-1;
        while(!span.empty() && idx>=0 && stock[idx] <= price) {
            s += span[idx];
            idx -= span[idx];
        }
        stock.push_back(price);
        span.push_back(s);
        return span.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

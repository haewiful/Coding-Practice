class SmallestInfiniteSet {
public:
    set<int> s;
    int largest;
    SmallestInfiniteSet() {
        largest = 1;
        s.insert(1);
    }
    
    int popSmallest() {
        if(s.empty()) {
            largest++;
            return largest;
        }
        int a = *s.begin();
        s.erase(s.begin());
        return a;
    }
    
    void addBack(int num) {
        if(largest >= num)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(c || a || b) {
            int a_1=a&1, b_1=b&1, c_1=c&1;
            if(c_1) {
                if((a_1|b_1)==0) {
                    count++;
                }
            } else {
                if(a_1) count++;
                if(b_1) count++;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }
};

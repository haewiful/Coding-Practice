class Solution {
public:
    int compress(vector<char>& chars) {
        int result = 0;
        char c = chars[0];
        int num=0;
        int idx=0;
        for(int i=0; i<chars.size(); i++) {
            if(c==chars[i]) {
                num++;
            } else {
                result++; // for the char itself
                chars[idx++]=c;
                if(num>1) {
                    int n = getDigitInNum(num);
                    for(int j=n-1; j>=0; j--) { // for the number
                        chars[idx+j] = '0'+num%10;
                        num/=10;
                    }
                    result+=n;
                    idx+=n;
                }
                c = chars[i];
                num=1;
            }
        }
        result++;
        chars[idx++]=c;
        if(num>1) {
            int n = getDigitInNum(num);
            for(int j=n-1; j>=0; j--) {
                chars[idx+j] = '0'+num%10;
                num/=10;
            }
            result+=n;
            idx+=n;
        }
        return result;
    }

    int getDigitInNum(int num) {
        // base case
        if(num/10==0) return 1;
        // recursive case
        return 1 + getDigitInNum(num/10);
    }
};

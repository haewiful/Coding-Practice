class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int gcd = getGcd(m, n);
        while(gcd>0) {
            // check
            string slice = str1.substr(0, gcd);
            int m_mult = m/gcd;
            int n_mult = n/gcd;
            string new_m = "";
            for(int i=0; i<m_mult; i++) {
                new_m += slice;
            }
            string new_n = "";
            for(int i=0; i<n_mult; i++) {
                new_n += slice;
            }
            if(new_m == str1 && new_n == str2) {
                return slice;
            }

            // get new gcd
            int new_gcd=0;
            for(int i=2; i<gcd; i++) {
                if(gcd%i==0) {
                    new_gcd = gcd / i;
                    break;
                }
            }
            if(new_gcd==0) break;
            gcd = new_gcd;
        }
        return "";
    }

    int getGcd(int m, int n) {
        while(n!=0) {
            int r = m%n;
            m = n;
            n = r;
        }
        return m;
    }
};

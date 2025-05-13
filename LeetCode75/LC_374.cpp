/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int g = n/2;
        int left=1, right=n;
        while(int result = guess(g)!=0) {
            if(result<0) { // g < num
                left = g;
                g = (left+right)/2;
            } else { // g > num
                right = g;
                g = (left+right)/2;
            }
        }
        return g;
    }
};

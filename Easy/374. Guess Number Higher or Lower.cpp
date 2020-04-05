/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int l = 1,r = n;
        int ans = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int g = guess(mid);
            if(g==0){
                 ans = mid;
                break;
            }
            else if(g== 1)
            {
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};

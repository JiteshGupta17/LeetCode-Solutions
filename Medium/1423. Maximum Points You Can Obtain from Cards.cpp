const int N = 100005;
class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        
        vector<int> pref(n+1,0);
        int sum = 0;
        
        for(int i = 0;i<n;i++)
        {
            sum += cardPoints[i];
            pref[i+1] = sum;
        }
        
        int ans = 0;
        int l = n-k;
        for(int i = n-k;i<=n;i++)
        {
            ans = max(ans,sum - (pref[i] - pref[i-l]));
        }
        
        return ans;
        
    }
};

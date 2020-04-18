class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        vector<int> fib;
        fib.push_back(1);
        
        int prev = 1;
        int cur = 2;
        
        while(cur <= k)
        {
            fib.push_back(cur);
            int next = cur + prev;
            
            prev = cur;
            cur = next;
        }
        
        int ans =0;
        while(k>0)
        {
            int l = lower_bound(fib.begin(),fib.end(),k) - fib.begin();
            if(l == fib.size() || fib[l] > k) l--;
            k -= fib[l];
            ans++;
            
        }
        
        return ans;
    }
};

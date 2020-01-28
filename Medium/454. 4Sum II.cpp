class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<long long int, long long int> mp;

        for (long long int a : A)
        {
            for (long long int b : B)
            {
                mp[a + b]++;
            }
        }

        long long int ans = 0;

        for (long long int c : C)
        {
            for (long long int d : D)
            {
                long long int sum = -(c + d);
                if (mp.find(sum) != mp.end())
                {
                    ans += mp[sum];
                }


            }
        }
        return ans;
    }
};
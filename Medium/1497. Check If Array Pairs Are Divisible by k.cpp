class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        vector<int> remainders(k);

        for (int ele : arr)
        {
            int rem = (k + ele % k) % k;
            remainders[rem]++;
        }

        if (remainders[0] & 1) return false;

        for (int i = 1; i <= k / 2; i++)
        {
            if (remainders[i] != remainders[k - i]) return false;
        }

        return true;
    }
};
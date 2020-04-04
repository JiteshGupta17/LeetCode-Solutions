// Method - 1
class Solution {
public:

    int maxConcat(int idx, int cur_val, vector<pair<int, int>> v)
    {
        if (idx == v.size()) return 0;

        int ans = 0;
        for (int i = idx; i < v.size(); i++)
        {
            if ((cur_val & v[i].second) == 0)
            {
                ans = max(ans, v[i].first + maxConcat(i + 1, cur_val | v[i].second, v));
            }
        }
        return ans;
    }

    int maxLength(vector<string>& arr) {

        vector<pair<int, int>> v;

        for (int i = 0; i < arr.size(); i++)
        {
            int val = 0;
            bool f = true;
            for (char ch : arr[i])
            {
                int mask = 1 << (ch - 'a');
                if ((val & mask) != 0)
                {
                    f = false; break;
                }
                val |= mask;
            }

            if (f) v.push_back({arr[i].length(), val});
        }

        return maxConcat(0, 0, v);
    }
};

// ==============================================================================================

// Method - 2 Using Bitset class
class Solution {
public:

    int maxConcat(int idx, bitset<26> cur_val, vector<bitset<26>> v)
    {
        if (idx == v.size()) return 0;

        int ans = 0;
        for (int i = idx; i < v.size(); i++)
        {
            if ((v[i] & cur_val) == 0) {
                int len = v[i].count();
                ans = max(ans, len + maxConcat(i + 1, v[i] | cur_val, v));
            }
        }

        return ans;
    }

    int maxLength(vector<string>& arr) {

        vector<bitset<26>> v;

        for (int i = 0; i < arr.size(); i++)
        {
            bitset<26> cur;
            for (char ch : arr[i])
            {
                cur.set(ch - 'a');
            }

            if (cur.count() == arr[i].length()) v.push_back(cur);
        }

        return maxConcat(0, bitset<26>(), v);
    }
};

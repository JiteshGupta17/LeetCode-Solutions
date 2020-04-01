// Method 1 - Bit Manipulation
class Solution {
public:

    string result_string(int val, vector<int> index, string s)
    {
        string cur = s;
        int i = 0;
        while (val)
        {
            if (val & 1) {
                cur[index[i]] ^= 1 << 5;
            }

            i++;
            val = val >> 1;
        }

        return cur;
    }

    vector<string> letterCasePermutation(string s) {

        vector<string> ans;
        vector<int> index;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (!isdigit(ch)) {
                cnt++;
                index.push_back(i);
            }
        }
        int possible = 1 << cnt;

        for (int i = 0; i < possible; i++)
        {
            ans.push_back(result_string(i, index, s));
        }

        return ans;
    }
};

// ===========================================================================================

// Method 2 - Using BackTracking
class Solution {
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};


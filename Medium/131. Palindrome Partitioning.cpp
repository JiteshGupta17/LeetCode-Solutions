class Solution {
public:
    vector<vector<string>> main_ans;

    bool isPalin(string s, int st, int end)
    {
        while (st < end) {
            if (s[st] != s[end]) return false;
            st++;
            end--;
        }

        return true;
    }

    void partition_recur(string s, int st, int end, vector<string>&ans) {

        if (st > end)
        {
            main_ans.push_back(ans);
            return;
        }

        for (int i = st; i <= end; i++)
        {
            if (i == st)
            {
                ans.push_back(string(1, s[i]));
                partition_recur(s, st + 1, end, ans);
                ans.pop_back();

                continue;
            }

            if (isPalin(s, st, i))
            {
                ans.push_back(s.substr(st, i - st + 1));
                partition_recur(s, i + 1, end, ans);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> ans;
        partition_recur(s, 0, s.length() - 1, ans);
        return main_ans;

    }
};

// Method - 1 (faster)
class Solution {
public:
    unordered_map<string, vector<char>> mp;

    vector<string> new_bottom(int idx, string bottom)
    {
        vector<string> ans;

        if (idx + 2 > bottom.length()) {
            ans.push_back("");
            return ans;
        }

        string cur = bottom.substr(idx, 2);

        if (mp.find(cur) == mp.end()) return ans;

        vector<string> recAns = new_bottom(idx + 1, bottom);

        for (char ch : mp[cur])
        {
            for (string temp : recAns)
            {
                ans.push_back(ch + temp);
            }
        }

        return ans;
    }

    bool pyramid(string bottom)
    {
        if (bottom.length() == 1) return true;

        vector<string> bottoms = new_bottom(0, bottom);
        bool res = false;
        for (string cur : bottoms)
        {
            if (cur.length() == bottom.length() - 1)
                res = res || pyramid(cur);

            if (res) break;
        }

        return res;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for (string ele : allowed)
        {
            string cur = ele.substr(0, 2);
            mp[cur].push_back(ele[2]);
        }

        bool ans =  pyramid(bottom);
        mp.clear();

        return ans;
    }
};

// ==========================================================================================

// Method - 2(slow)
class Solution {
public:

    bool pyramid(string bottom, unordered_map<string, vector<int>> mp, int idx, string combined)
    {
        if (bottom.length() == 1) return true;

        if (combined.length() == bottom.length() - 1)
            return pyramid(combined, mp, 0, "");

        for (char ch : mp[bottom.substr(idx, 2)])
        {
            if (pyramid(bottom, mp, idx + 1, combined + ch)) return true;
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        unordered_map<string, vector<int>> mp;
        for (string ele : allowed)
        {
            string cur = ele.substr(0, 2);
            mp[cur].push_back(ele[2]);
        }

        bool ans =  pyramid(bottom, mp, 0, "");

        return ans;
    }
};

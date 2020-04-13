// Least time - 12ms
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;
        for (auto ch : s) mp[ch]++;


        vector<pair<int, char>> v;
        for (auto ele : mp)
        {
            v.push_back({ele.second, ele.first});
        }

        sort(v.begin(), v.end());

        string ans = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += string(v[i].first, v[i].second);
        }

        return ans;

    }
};

// ======================================================================

// Without using inbuilt sort - 32ms
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> bucket(s.size() + 1, "");
        string res;

        //count frequency of each character
        for (char c : s) freq[c]++;
        //put character into frequency bucket
        for (auto& it : freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c); // apeend char c , n times
        }
        //form descending sorted string
        for (int i = s.size(); i > 0; i--) {
            if (!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};

// =========================================================================

// Greater time but nice approach - 76ms
class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) {
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
        });
        return s;
    }
};


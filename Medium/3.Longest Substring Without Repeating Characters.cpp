// 24ms
int lengthOfLongestSubstring(string s) {

    map<char, bool> m;

    int r = 0;
    int ans = 0;

    for (int l = 0; l < s.length(); l++)
    {
        while (r < s.length() && !m[s[r]])
        {
            m[s[r]] = true;
            r++;
        }

        ans = max(ans, r - l);
        m[s[l]] = false;

    }

    return ans;

}

// 8ms
int lengthOfLongestSubstring(string s) {

    vector<int> dict(256, -1);

    int maxLen = 0, start = -1;

    for (int i = 0; i != s.length(); i++) {

        // As soon as we get a repeated char, we make it the start of new substring
        // as previous substring length is calculated at each iuteration
        if (dict[s[i]] > start)
            start = dict[s[i]];

        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }

    return maxLen;
}
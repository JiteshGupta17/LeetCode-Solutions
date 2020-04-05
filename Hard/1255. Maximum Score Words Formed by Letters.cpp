class Solution {
public:

    int max_score(int idx, vector<string>& words, vector<int>& chars, vector<int>& score)
    {
        if (idx == words.size()) return 0;

        int ans = 0;
        for (int i = idx; i < words.size(); i++)
        {
            int cur = 0;
            int j = 0;
            for (j; j < words[i].length(); j++)
            {
                char ch = words[i][j];

                if (chars[ch - 'a'] > 0) {
                    cur += score[ch - 'a'];
                    chars[ch - 'a']--;
                }
                else break;
            }

            if (j == words[i].length())
            {
                ans = max(ans, cur + max_score(i + 1, words, chars, score));
            }

            for (j = j - 1; j >= 0; j--)
            {
                char ch = words[i][j];
                chars[ch - 'a']++;
            }
        }
        return ans;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        vector<int> chars(26, 0);
        for (char ch : letters)
        {
            chars[ch - 'a']++;
        }

        return max_score(0, words, chars, score);
    }
};

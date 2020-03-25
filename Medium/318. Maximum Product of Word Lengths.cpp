// Method 1 - Most trivial O of N^2 as only 26 letter so we dont need any array and can just map letter with bit position
// and two nos. will have different letters only when value mapped to them will not have any common bit as 1
// and ultimately their AND will be zero
class Solution {
public:
    int maxProduct(vector<string>& words) {

        vector<int> num(words.size());

        int max_ans = 0;
        int cur;
        for (int i = 0; i < words.size(); i++)
        {
            for (char ch : words[i])
                num[i] |= 1 << (ch - 'a');

            // By doing this we have all val precalculated for a given word
            for (int j = 0; j < i; j++)
            {
                if ((num[i]&num[j]) == 0)
                {
                    cur = words[i].length() * words[j].length();
                    max_ans = max(max_ans, cur);
                }
            }
        }

        return max_ans;
    }


};

// Method 2
class Solution {
public:

    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maxlen;
        for (string word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            maxlen[mask] = max(maxlen[mask], (int) word.size());
        }
        int result = 0;
        for (auto a : maxlen)
            for (auto b : maxlen)
                if (!(a.first & b.first))
                    result = max(result, a.second * b.second);
        return result;
    }

};

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        // stores the mapping of each word to int
        unordered_map<int, int> mp;

        for (string word : words)
        {
            int mapped_value = 0;
            for (char ch : word)
            {
                mapped_value |= (1 << (ch - 'a'));
            }

            mp[mapped_value] ++;
        }

        vector<int> ans(puzzles.size());

        for (int i = 0; i < puzzles.size(); i++)
        {
            int cur_ans = 0 ;
            int mapped_value = 0;

            for (char ch : puzzles[i])
            {
                mapped_value |= (1 << (ch - 'a'));
            }

            int first_char = 1 << (puzzles[i][0] - 'a');

            int subsets = mapped_value;
            // This while can run max 2^7 as max possible length of puzzle is 7
            while (subsets)
            {
                if (((first_char & subsets) == first_char) && mp.find(subsets) != mp.end())
                {
                    cur_ans += mp[subsets];
                }

                subsets = (subsets - 1) & mapped_value; // give all the possible combinations
            }

            ans[i] = cur_ans;
        }

        return ans;

    }
};

// Method - 1
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> mp;
        vector<string> ans;

        // Mapping them from 0 to 3 which can be represented as 2 bits
        unordered_map<char, int> charToNum;
        charToNum['A'] = 0;
        charToNum['C'] = 1;
        charToNum['G'] = 2;
        charToNum['T'] = 3;

        // 10 letter seq with each letter represented by 2 bits can be represented as unique 20 bit number

        int hashVal = 0;
        for (int i = 0; i < 10; i++)
        {
            hashVal = hashVal << 2 | charToNum[s[i]];
        }

        mp[hashVal]++;

        // Mask with set 19th and 18th bit
        int mask = (1 << 19) | (1 << 18);

        for (int i = 10; i < s.length(); i++)
        {
            // Done to reset the 19th and 18th bit as it was due to char of previous window
            hashVal = hashVal & ~mask;

            // Updating value by present window last char
            hashVal = hashVal << 2 | charToNum[s[i]];

            mp[hashVal]++;
            if (mp[hashVal] == 2)
            {
                ans.push_back(s.substr(i - 9, 10));
            }
        }


        return ans;
    }
};

// Method - 2
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string, int> mp;
        vector<string> ans;

        for (int i = 0; i + 10 <= s.length(); i++)
        {
            string cur = s.substr(i, 10);
            mp[cur]++;
            if (mp[cur] == 2)
            {
                ans.push_back(cur);
            }
        }


        return ans;
    }
};

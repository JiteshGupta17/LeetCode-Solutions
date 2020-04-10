// Method 1 - Trie and DFS (less time but more space)
class TrieNode {
public:

    TrieNode* children[26] = {NULL};
    bool terminal;

    TrieNode()
    {
        terminal = false;
    }
};

class Solution {
public:
    void insert(TrieNode* root, string word)
    {
        TrieNode* temp = root;
        for (char ch : word)
        {
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else {
                TrieNode* n = new TrieNode();
                temp->children[ch - 'a'] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool search(TrieNode*root, string word, int i, int cnt)
    {
        // Handling the base case in for loop itself to prevent extra calls
        // if(i==word.length())
        //     return cnt > 1;

        TrieNode* temp = root;
        int n = word.length();
        for (int idx = i ; idx < n; idx++)
        {
            char ch = word[idx];
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];

                if (temp->terminal)
                {
                    if (idx == n - 1) return cnt >= 1 ; // Handling base case
                    if (search(root, word, idx + 1, cnt + 1))return true;

                }
            }
            else return false;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans ;
        if (words.size() == 0) return ans;

        TrieNode* root = new TrieNode();


        for (string word : words)
        {
            if (word.length() == 0) continue;
            insert(root, word);
        }

        for (string word : words)
        {
            if (word.length() == 0) continue;
            if (search(root, word, 0, 0))
                ans.push_back(word);
        }


        return ans;

    }
};

// ========================================================================================

// Method 2 - DP just like word Break (More time less space)
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& set)
    {
        if (set.empty()) return false;

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            string combine = "";
            int len = n - i;
            for (int j = 0; j < len; j++)
            {
                combine += s[i + j];
                if (dp[i + j + 1] && set.count(combine))
                {
                    dp[i] = true;
                    break;
                }
            }
            // cout<<dp[i]<<" ";
        }
        return dp[0];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        vector<string> ans ;
        if (words.empty()) return ans;

        auto mycomp = [&](const string & str1, const string & str2) {return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);

        unordered_set<string> set;
        // for(auto &word : words) must use auto and & always
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].length() == 0) continue;
            if (wordBreak(words[i], set))
                ans.push_back(words[i]);
            set.insert(words[i]);
        }

        return ans;

    }
};

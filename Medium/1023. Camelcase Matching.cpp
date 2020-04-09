class TrieNode {
public:

    char data;
    unordered_map<char, TrieNode*> children;
    bool terminal;

    TrieNode(char ch)
    {
        data = ch;
        terminal = false;
    }
};


class Solution {
public:

    vector<bool> camelMatch(vector<string>& queries, string pattern) {

        TrieNode* root = new TrieNode('\0');

        TrieNode*cur = root;

        for (char ch : pattern)
        {
            TrieNode* n = new TrieNode(ch);
            cur->children[ch] = n;
            cur = n;
        }
        cur->terminal = true;

        vector<bool> ans;

        for (string s : queries)
        {
            cur = root;
            bool f = true;

            for (char ch : s)
            {
                if (cur->children.count(ch))
                {
                    cur = cur->children[ch];
                }
                else if (islower(ch))
                {
                    continue;
                }
                else if (isupper(ch))
                {
                    f = false;
                    break;
                }
            }
            f = f && cur->terminal;
            ans.push_back(f);
        }

        return ans;
    }
};

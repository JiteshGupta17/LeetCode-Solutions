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

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    MagicDictionary() {
        root = new TrieNode('\0');
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {

        for (string s : dict)
        {
            TrieNode* temp = root;
            for (char ch : s)
            {
                if (temp->children.count(ch))
                {
                    temp = temp->children[ch];
                }
                else {
                    TrieNode* n = new TrieNode(ch);
                    temp->children[ch] = n;
                    temp = n ;
                }
            }
            temp->terminal = true;
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */

    bool mysearch(int i, TrieNode* temp, string word, int once)
    {
        if (i == word.length()) return temp->terminal && once == 1;

        bool res1 = false;
        char ch = word[i];

        if (temp->children.count(ch)) {
            res1 =  mysearch(i + 1, temp->children[ch], word, once);
        }
        
        bool res = false;
        if (once == 0)
        {
            for (auto x : temp->children)
            {
                if (x.first != ch)
                    res = res || mysearch(i + 1, x.second, word, 1);
            }
        }
        return res1 || res;
    }

    bool search(string word) {

        return mysearch(0, root, word, 0);

    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

class Node {
public:
    char data;
    vector<Node*>children;
    bool terminal ;
    Node(char ch)
    {
        data = ch;
        children = vector<Node*>(26,NULL);
        terminal = false;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node* root;
    WordDictionary() {
        root = new Node('\0');
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {

        Node* temp = root;
        for (char ch : word)
        {
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else {
                Node* n = new Node(ch);
                temp->children[ch - 'a'] = n;
                temp = n;
            }
        }
        temp->terminal = true;

    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */

    bool mySearch(int i, string word, Node* cur)
    {
        if (i == word.length()) {
            return cur->terminal;
        }

        char ch = word[i];
        if (isalpha(ch))
        {
            if (cur->children[ch - 'a'])
            {
                return mySearch(i + 1, word, cur->children[ch - 'a']);
            }
            else return false;
        }

        bool res = false;
        for (int j = 0; j < 26; j++)
        {
            if (cur->children[j])
                res = res || mySearch(i + 1, word, cur->children[j]);
        }
        return res;
    }

    bool search(string word) {
        return mySearch(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

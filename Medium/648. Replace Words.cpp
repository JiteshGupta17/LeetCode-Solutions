class Node{
public:
    char data;
    Node* children[26] = {NULL};
    bool terminal;
    
    Node(char ch)
    {
        data = ch;
        terminal = false;
    }
    
};

class Solution {
public:

    void insert(Node* root,string word)
    {
        Node* temp = root;
        for(char ch : word)
        {
            if(temp->children[ch-'a'])
            {
                temp = temp->children[ch-'a'];
            }
            else{
                Node * n = new Node(ch);
                temp->children[ch-'a'] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    string find(Node*root,string word)
    {
        string pre = "";
        Node* temp = root;

        for(int i = 0;i<word.length();i++)
        {
            char ch = word[i];
            if(temp->children[ch-'a'])
            {
                temp = temp->children[ch-'a'];
                pre += ch;
                if(temp->terminal) break;
            }
            else{
                return word;
            }
        }
        return pre;
    }

    string replaceWords(vector<string>& dict, string sentence) {
        
        Node* root = new Node('\0');

        for(string s : dict) insert(root,s);

        string ans = "";
        string combined = "";
        for(int i = 0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                ans += find(root,combined);
                combined.clear();
                ans += ' ';
            }
            else combined.push_back(sentence[i]);
        }

        ans += find(root,combined);
        return ans;
    }
};

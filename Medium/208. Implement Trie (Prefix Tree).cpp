#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58842/Maybe-the-code-is-not-too-much-by-using-%22next26%22-C%2B%2B

class Node {
public:
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char d) {
        data = d;
        terminal = false;
    }
};

class Trie {
    Node* root;
    int cnt;

public:

    Trie() {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(string w) {

        Node* temp = root;
        for (int i = 0; w[i] != '\0'; i++) {

            char ch = w[i];
            if (temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(string w) {
        Node* temp = root;
        for (int i = 0; w[i] != '\0'; i++) {
            char ch = w[i];
            if (temp->children.count(ch) == 0) {
                return false;
            }
            else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (char ch : prefix)
        {
            if (temp->children.count(ch))
            {
                temp = temp->children[ch];
            }
            else return false;
        }
        return true;
    }
};

int main() {

    Trie t;
    vector<string> words = {"news", "not", "apple", "ape"};
    for (string s : words) t.insert(s);

    if (t.find("no")) cout << "Present\n";
    else if(t.startsWith("no")) cout<<"Prefix\n";
    else cout<<"Absent\n";

}


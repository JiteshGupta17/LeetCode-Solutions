class TrieNode {
public:

    TrieNode* left; // Represents 0
    TrieNode* right; // Represents 1

    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    void insert(TrieNode* root, int ele)
    {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (ele >> i) & 1; // or bit = (1<<i) & ele ? 1 : 0;
            if (bit == 0)
            {
                if (cur->left) cur = cur->left; //if already present else create a new one
                else {
                    TrieNode* n = new TrieNode();
                    cur->left = n;
                    cur = n;
                }
            }
            else {
                if (cur->right) cur = cur->right; //if already present else create a new one
                else {
                    TrieNode* n = new TrieNode();
                    cur->right = n;
                    cur = n;
                }
            }
        }
    }

    int FIndMaxXorPair(TrieNode* root, int ele)
    {
        TrieNode* cur = root;
        int result = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (ele >> i) & 1;

            if (bit == 0)
            {
                // cur_bit of element is 0 and we need to find a 1 if present
                if (cur->right)
                {
                    result |= (1 << i);
                    cur = cur->right;
                }
                else cur = cur->left; // No other option other than going left
            }
            else {
                // cur_bit of element is 1 and we need to find a 0 if present
                if (cur->left)
                {
                    result |= (1 << i);
                    cur = cur->left;
                }
                else cur = cur->right; // No other option other than going right
            }
        }
        return result;
    }
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < nums.size(); i++)
        {
            insert(root, nums[i]);
            int cur_max_pair = FIndMaxXorPair(root, nums[i]);
            result = max(cur_max_pair, result);
        }

        return result;
    }
};

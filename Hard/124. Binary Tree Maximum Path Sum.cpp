
class Solution {
public:
    // There can be 4 ways
    // a
    //  \
    //   b
    //  / \
    // c   d

    // c and d are maximum from left and right respecitvely not nodes

    // lets consider node b
    // so the possible answeres can be -
    // 1. b - node itself when all node negative then least - ve will be ans
    // 2. b + c
    // 3. b + d
    // 4. leftmax i.e c + rightmax i.e d + itself
    // out of these 4 possible values - first 3 are sent as ans to the recursion call
    // because the 4th one is complete path (c- b -d) and cant be extended upwards

    int ans ;

    int helper(TreeNode* cur)
    {
        if (cur == NULL) return 0;

        int l = helper(cur->left);
        int r = helper(cur->right);

        int cur_max = max(cur->val, max(l + cur->val, r + cur->val)); // 1,2,3
        ans = max(ans, max(cur_max, l + r + cur->val));

        return cur_max;
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        ans = max(ans, helper(root));
        return ans;
    }
};

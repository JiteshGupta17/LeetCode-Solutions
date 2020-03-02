bool isSubPath(ListNode* head, TreeNode* root) {

    if (!head) return true;
    if (!root) return false;

    return Helper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);

}

bool Helper(ListNode* head, TreeNode* root)
{
    if (!head) return true;
    if (!root) return false;
    return head->val == root->val && (Helper(head->next, root->left) || Helper(head->next, root->right));
}

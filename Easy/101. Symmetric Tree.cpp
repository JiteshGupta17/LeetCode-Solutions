//Recursive
bool Symm_recur(TreeNode* t1, TreeNode* t2)
{
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;

    return (t1->val == t2->val) && Symm_recur(t1->left, t2->right) && Symm_recur(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {

    if (!root) return true;

    return Symm_recur(root->left, root->right);
}

// =====================================================================================

//Iterative - BFS
bool isSymmetric(TreeNode* root) {

// Kind of level order checking, just one major diff is that
// in level order we push left and right of first and then left and right of seconf
    /*         a
              b b
            c d d c
        e f g h h g f e */
// Queue after each iteration
// b,b
// c,c,d,d
// d,d,e,e,f,f
// e,e,f,f,g,g,h,h and so on

    if (!root) return true;

    queue<pair<TreeNode*, TreeNode*>> q;

    q.push({root->left, root->right});

    while (!q.empty()) {

        auto p = q.front();
        q.pop();

        if (!p.first && !p.second) continue;
        if (!p.first || !p.second) return false;

        if (p.first->val != p.second->val) return false;

        q.push({p.first->left, p.second->right});
        q.push({p.first->right, p.second->left});
    }
    return true;
}

//Iterative - DFS
bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    stack<TreeNode*> sl, sr;
    sl.push(root);
    sr.push(root);

    TreeNode * lp = root->left, *rp = root->right;

    while (lp || ! sl.empty() || rp || !sl.empty()) {

        if ((!lp && rp) || (lp && !rp)) return false;

        if (lp && rp) {
            if (lp->val != rp->val) return false;

            sl.push(lp);
            sr.push(rp);

            lp = lp->left;
            rp = rp->right;
            
        } else {

            lp = sl.top()->right;
            rp = sr.top()->left;

            sl.pop();
            sr.pop();
        }
    }
    return true;
}

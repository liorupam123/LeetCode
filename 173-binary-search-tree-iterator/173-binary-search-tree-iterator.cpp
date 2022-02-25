/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// T.C --> O(1)
// S.C --> O(n) --> with stack

class BSTIterator {
public:
    stack<int>s;
    
    void load(TreeNode* root){
        if(!root) return;
        load(root->right);
        s.push(root->val);
        load(root->left);
    }
  
    BSTIterator(TreeNode *root) {
        load(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        int n = s.top();
        s.pop();
        return n;
    }
    
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
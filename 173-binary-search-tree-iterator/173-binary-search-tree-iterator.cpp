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
// S.C --> O(h) --> with stack

class BSTIterator {
public:
  
    stack<TreeNode*>s;
    
    // go to extreme left and push everything into the stack
    void load(TreeNode* root){
        if(!root) return;
        s.push(root);
        load(root->left);
    }
    BSTIterator(TreeNode *root) {
        load(root);
    }

    /* return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    // when it comes to return the next, store the top and pop
    // if the top element has right subtree, call the load function to store it into the stack
    // else return the node->val
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(node->right) load(node->right);
        return node->val;
    }
    
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
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

/* 1. if we are selecting root, we can not select root's right and left. Then we can select 
root's right->left right->right and left->left left->right 

2. if we are not selecting root, then select root->right and root->left

ans = max(1,2)

*/


class Solution {
public:
    unordered_map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(m.count(root)) return m[root];
        if(!root) return 0;
        int self = root->val;
        if(root->left) self += (rob(root->left->left) + rob(root->left->right));
        if(root->right) self += (rob(root->right->left) + rob(root->right->right));
        int nself = (rob(root->left) + rob(root->right));
        m[root] = max(self ,nself);
        return m[root];
    }
};
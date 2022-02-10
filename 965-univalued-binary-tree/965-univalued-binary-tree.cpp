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
class Solution {
    bool dfs(TreeNode* root, int val) {
        if(!root) return true;
        if(root->val != val) return false;
        return dfs(root->left, val) && dfs(root->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
		//Send the value and root to helper and just check every value is equal 
		// to the root->value
        return dfs(root, root->val);
    }
};
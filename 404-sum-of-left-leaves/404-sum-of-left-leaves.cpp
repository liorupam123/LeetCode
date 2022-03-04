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

// if left==null and right==null then leaves --> 9+15+7
// but here only 9 and 15, root's left part only
// so, root->left!=null and root->left ka right and left == null
class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(root != NULL) // root should not be null
        {
            // root left should not be null && root -> left's left and right should be null
            if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            {
                ans += root->left->val;
            }
            // checking for right and left root's left leaf node
            sumOfLeftLeaves(root->left);
            sumOfLeftLeaves(root->right);
        }
        return ans;
    }
};
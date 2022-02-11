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
public:
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root == NULL)  return false;
  
        // when we have reached the leaf nodes and rootvalue-targetsum==0, we have found the path
        // so return true
        if(root->left == NULL && root->right == NULL && root->val - targetSum == 0)
              return true;
        // else, call the recursion for right subtree and left subtree and always subtract the rootvalue from the target sum
        bool left = hasPathSum(root->left,targetSum - root->val);
        bool right = hasPathSum(root->right,targetSum - root->val);
        
        // OR because any one from left right will return true, 0 1 --> 1 / 1 0 --> 1
        return left || right;
    }
};
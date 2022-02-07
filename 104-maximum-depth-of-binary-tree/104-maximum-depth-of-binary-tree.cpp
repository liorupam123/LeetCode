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

// Depth of a binary tree means the deepest path to the leaf node from the root node, so we have to check the leaf nodes on both of the left and right sides. After that return the 1 + max(left,right)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        // go to the left & right and check the max depth 
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right);
        
        // return the max of left and right + 1
        return 1 + max(lh, rh);
    }
};
// T.C == O(N) All the nodes, because we have traverse all the nodes of left and right.
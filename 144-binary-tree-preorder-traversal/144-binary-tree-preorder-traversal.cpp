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

// preorder means root, left , right
class Solution {
    private:
    void dfs(TreeNode *node, vector<int> &preorder) {
        if(node == NULL) return; 
        
        // at first push the root's value
        preorder.push_back(node->val);
        // then call the dfs function for the left half of the tree
        dfs(node->left, preorder); 
        // then call the dfs function for the left right of the tree
        dfs(node->right, preorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector to store
        vector<int> preorder; 
        dfs(root, preorder);
        return preorder; 
    }
};
// T.C — O(N) N == number of nodes
// S.C — O(Height)  — O(N) worst, for skew tree Space for recursion
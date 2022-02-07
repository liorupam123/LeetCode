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

// inorder means == left, root, right
class Solution {
private:
    void dfs(TreeNode *node, vector<int> &inorder) {
        if(node == NULL) return; 
        
        // at first call the dfs function for the left half of the tree
        dfs(node->left, inorder);
        // then push the root's value
        inorder.push_back(node->val);
        // then call the dfs function for the left right of the tree
        dfs(node->right, inorder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector to store
        vector<int> inorder;
        dfs(root, inorder);
        return inorder; 
    }
};
// T.C — O(N) N == number of nodes
// S.C — O(Height)  — O(N) worst, for skew tree Space for recursion
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

// post order means == left , right , root
class Solution {
    private:
    void dfs(TreeNode *node, vector<int> &postorder) {
        if(node == NULL) return; 
        
        // at first call the dfs function for the left half of the tree
        dfs(node->left, postorder);
        // then call the dfs function for the left right of the tree
        dfs(node->right, postorder);
        // at last push the root's value
        postorder.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector to store
        vector<int> postorder;
        dfs(root, postorder);
        return postorder; 
    }
};
// T.C — O(N) N == number of nodes
// S.C — O(Height)  — O(N) worst, for skew tree Space for recursion
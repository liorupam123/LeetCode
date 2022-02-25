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
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        // always maintain the upper bound of the node
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        // when the pointer is reached out of the end of the vector, return null
        // or we can't place the node for the upper bound limit, return NULL
        if (i == A.size() || A[i] > bound) return NULL;
      
        // make a tree node as the new element of the vector A[i++]
        TreeNode* root = new TreeNode(A[i++]);
        // left means smaller than root, upper bound is the root value
        root->left = build(A, i, root->val);
        // right means greater than root, upper bound is the INT_MAX
        root->right = build(A, i, bound);
        return root;
    }
};
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
    int kthSmallest(TreeNode* root, int k) {
        int kthElement;
        helper(root, k, kthElement);
        return kthElement;
    }
    // use inorder traversal
    void helper(TreeNode* cur, int &k, int &kthElement) {
        if (cur == NULL) {
            return;
        }
        // go to left subtree where the smaller node is present
        helper(cur->left, k, kthElement);
        // k-- after every step of iteration..
        k--;
        
        // when k==0, that particular node is the answer.
        if (k == 0) { 
            // update the answer and return
            kthElement = cur->val; 
            return;
        }
        // then go to right.. inorder ==> left root right
        helper(cur->right, k, kthElement); 
    }
};
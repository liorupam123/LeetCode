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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val); // if root is null return the val as a node..
        TreeNode *cur = root; // make a copy of root coz at the end we have to return that
        while(true) {
            if(cur->val <= val) { // val is greater than curr val, go to right
                if(cur->right != NULL) cur = cur->right; // if right != null , go right again
                else {
                    cur->right = new TreeNode(val); // right== nulll, insert the val as a node
                    break; // break and return
                }
            } else { // val is smaller than curr val, go to left
                if(cur->left != NULL) cur = cur->left;// if left != null , go left again
                else {
                    cur->left = new TreeNode(val);// left== nulll, insert the val as a node 
                    break; // break and return
                }
            }
        }
        return root;
    }
};
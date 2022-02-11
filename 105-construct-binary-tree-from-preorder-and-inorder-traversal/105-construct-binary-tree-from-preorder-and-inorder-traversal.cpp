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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        // creat a map to store inorder's node and index
        map<int, int> inMap; 
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // preorder , start , end and inorder , start , end 
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
    
   TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        
        // edge case
        if(preStart > preEnd || inStart > inEnd) return NULL;

        // preorder's first node == root
        TreeNode* root = new TreeNode(preorder[preStart]); 
        // where the root is stand in the inorder, the index
        int inRoot = inMap[root->val];
        // check how many roots are at the left
        int numsLeft = inRoot - inStart; 

        // watch striver's dry run video for that
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};
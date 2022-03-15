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
     TreeNode* construct(unordered_map<int, int>& mp, vector<int>& postorder, int start, int end, int &current)
    {
        if(start>end) return NULL;
        TreeNode *root = new TreeNode(postorder[current]);
        int index = mp[postorder[current]];
      
        current--;
        
        root -> right = construct(mp,postorder,index+1,end,current);
        root -> left = construct(mp,postorder,start,index-1,current);
        
      
        return root;
      
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int current = postorder.size()-1;
        return construct(mp,postorder ,  0, inorder.size() - 1, current);
    }
};
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
     TreeNode* construct(unordered_map<int, int>& mp, vector<int>& preorder, int start, int end, int &current)
    {
        if(start>end) return NULL;
        TreeNode *root = new TreeNode(preorder[current]);
        int index = mp[preorder[current]];
      
        current++;
        
        root -> left = construct(mp,preorder,start,index-1,current);
        root -> right = construct(mp,preorder,index+1,end,current);
      
        return root;
      
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.size());
        for(int i=0;i<preorder.size();i++){
          inorder[i] = preorder[i];
        }
        sort(inorder.begin(),inorder.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int current = 0;
        return construct(mp, preorder, 0 , inorder.size() - 1, current);
    }
};
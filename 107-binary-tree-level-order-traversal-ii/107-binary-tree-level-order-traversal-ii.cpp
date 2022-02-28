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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        // take a queue
        queue<TreeNode*> q;
        // push the root at first
        q.push(root);
        while(!q.empty()) {
            // taking the size of the queue for every level
            int size = q.size();
            // this vector is storing the levels for vector<vector>> int
            vector<int> level;
            for(int i = 0;i<size;i++) {
                // taking the front of the queue as a node
                TreeNode *node = q.front();
                q.pop(); 
                // push the main node value into the level
                level.push_back(node->val); 
                //then checking it's left
                if(node->left != NULL) q.push(node->left);
                // checking it's right
                if(node->right != NULL) q.push(node->right); 
                
            }
            // push the level into the main answer
            ans.push_back(level); 
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
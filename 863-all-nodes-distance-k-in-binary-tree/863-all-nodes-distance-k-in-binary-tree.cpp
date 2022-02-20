/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // storing the parent node of the current node
    void populateMap(TreeNode* currentNode,TreeNode *currentParent,unordered_map<TreeNode*,TreeNode*>&parentMap){
        if(currentNode == NULL) return;
        // here storing map[5] = 3
        parentMap[currentNode] = currentParent;
        // calling for right and left subtree
        populateMap(currentNode->left,currentNode,parentMap);
        populateMap(currentNode->right,currentNode,parentMap);
        return;
    }
    
    void printKDistance(TreeNode* currentNode,int k,set<TreeNode*>&st,unordered_map<TreeNode*,TreeNode*>&parentMap,vector<int>&ans){
        // if currentnode is present in the set return
        if(currentNode == NULL || st.find(currentNode)!=st.end() || k<0){
            return;
        }
        // everytime push the currentnode into the set
        st.insert(currentNode);
        // whenever k==0 thats mean we have reached the final node, push the val into the ans
        if(k==0){
            ans.push_back(currentNode->val);
            return;
        }
        // right and left subtree and parentnode
        // every time decrease the k by 1
        printKDistance(currentNode->left,k-1,st,parentMap,ans);
         printKDistance(currentNode->right,k-1,st,parentMap,ans);
         printKDistance(parentMap[currentNode],k-1,st,parentMap,ans);
        return;
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        // unique nodes so we take set
        set<TreeNode*>st;
        // map of currentNode and ParentNode
        unordered_map<TreeNode*,TreeNode*> parentMap;
        populateMap(root,NULL,parentMap);
        printKDistance(target,k,st,parentMap,ans);
        return ans;
    }
};

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
     struct TrieNode {
       TrieNode* children[26];
       int feq;
       
       TrieNode() {
           for(int i = 0; i < 26; i++)
               children[i] = NULL;
           feq = 0;   
       }
   };
   
   void insertNode(string s, TrieNode* root) {
       TrieNode* curr = root;
       
       for(char c: s)
       {
           if(curr->children[c - 'a'] == NULL) {
               curr->children[c - 'a'] = new TrieNode();
           }
           
           curr->feq++;
           curr = curr->children[c - 'a'];
       }
   }
   
   string getPrefix(string s, TrieNode* root) {
       
       TrieNode* curr = root;
       string pre = "";
       for(char c: s) {
           if(curr->feq == 1)
               return pre;
       
           pre += c;
           
           curr = curr->children[c - 'a'];
       }
       
       return pre;
   }
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
          TrieNode* root = new TrieNode();
       for(int i = 0; i < n; i++)
           insertNode(arr[i], root);
           
       vector<string> ans;
       for(int i = 0; i < n; i++)
           ans.push_back(getPrefix(arr[i], root));
           
       return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends
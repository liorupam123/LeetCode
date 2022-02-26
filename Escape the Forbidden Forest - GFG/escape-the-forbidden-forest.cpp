// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends
class Solution
{
    public:
     int findlcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i >= s1.size() || j >= s2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return 1 + findlcs(i + 1, j + 1, s1, s2, dp);
        }
        else{
            int left = findlcs(i + 1, j, s1, s2, dp );
            int right = findlcs(i, j+1, s1, s2, dp);
            dp[i][j] = max(left, right);
            return dp[i][j];
        }
    }
    
    
    int build_bridges(string str1, string str2)
    {
        //For finding the max length of the bridge, we just need to find the length of longest common subsequence of the strings
        //Which we can easily do using memoziation technique 
        //Initializing a dp 2d matrix;
        vector<vector<int>> dp (str1.size(), vector<int> (str2.size(), -1));
        return findlcs(0, 0, str1, str2, dp);   
    }
};

// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends
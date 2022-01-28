// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
         stack<string> stk;
       S=S+'.';
       string word = "";
       for(int i=0;i<S.length();i++){
           if(S[i]!='.'){
               word+=S[i];
           }else{
               stk.push(word);
               word="";
           }
       }
       string res="";
       while(!stk.empty()){
           res+=stk.top()+'.';
           stk.pop();
       }
       res.pop_back();
       return res;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
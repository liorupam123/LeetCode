// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
        stack<pair<char,int>> st ;
       
       int n = s1.size() ;
       
       for(int i=0;i<n;i++)
       {
           if(s2[i]!='#')
               st.push({s2[i],i}) ;
       }
       
       for(int i=n-1;i>=0;i--)
       {
           if(s1[i]=='#')
               continue ;
           
           if(st.empty() || s1[i]!=st.top().first)
               return "No" ;
           
           if(s1[i]=='A' && st.top().second<=i)
               st.pop() ;
           if(s1[i]=='B' && st.top().second>=i)
               st.pop() ;
       }
       
       if(st.empty())
           return "Yes" ;
           
       return "No" ;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
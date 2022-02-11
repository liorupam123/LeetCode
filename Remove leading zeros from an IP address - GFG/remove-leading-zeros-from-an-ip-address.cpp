// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        //code here.
         string k="";
       int counter = 0;
       for(int i=0;i<s.length();)
       {
           
       if(counter==0&&i==s.length()-1&&s[i]=='0')
         {
             char t='0';
             k.push_back(t);
             i++;
         }
         
        else if(counter==0&&s[i]=='0')
         {
             i++;
         }
         
         else if(counter==0&&s[i]=='.')
         {
             char z = '0';
             char m = '.';
             k.push_back(z);
             k.push_back(m);
             counter=0;
             i++;
         }
         
         else if(counter==1&&s[i]=='.')
         {
             counter=0;
             k.push_back(s[i]);
             i++;
         }
         
         
         else
         {
             k.push_back(s[i]);
             i++;
             counter=1;
         }
       }
       return k;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends
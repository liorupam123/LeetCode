// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
   
    public:
    vector<int> leaders(int a[], int n){
        
        vector<int> ans;
        ans.push_back(a[n-1]);
        int prev = a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>=prev){
                ans.push_back(a[i]);
                // updating the previous element
                prev = a[i];
            } 
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}
// } Driver Code Ends


int* greaterElement(int arr[], int n)
{
    // Complete the function
    int temp[n];
   for(int i = 0; i < n; i++) temp[i] = arr[i];
   sort(arr,arr+n);
   unordered_map<int,int> mp;
   for(int i = 0; i < n; i++){
       if(mp.find(arr[i]) != mp.end()) continue;
       int ub = upper_bound(arr+i+1,arr+n,arr[i]) - arr;
       if(ub == n) mp[arr[i]] = -1e7;
       else mp[arr[i]] = arr[ub];
   }
   
   int *ans = new int[n];
   for(int i = 0; i < n; i++){
       ans[i] = mp[temp[i]];
   }
   return (ans);
}

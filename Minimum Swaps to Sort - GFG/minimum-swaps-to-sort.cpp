// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int count = 0;
   int n = nums.size();
   vector<pair<int,int>>brr(n);
   
   for(int i=0;i<n;i++)
   {
       brr[i]=make_pair(nums[i],i);
   }
   
   sort(brr.begin(),brr.end());
   
   for(int i=0;i<n;i++)
   {
       if(i!=brr[i].second)
       {
           swap(brr[i],brr[brr[i].second]);
           count++;
           i--;
       }
   }
   
   return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
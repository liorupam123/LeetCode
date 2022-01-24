// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        
		// Your code here
	   long low = 1;
	   long high = x;
	   while (low <= high) {
	       long mid = low + (high - low) / 2;
	       if (mid == x / mid) return mid;
	       else if (mid < x / mid) low = mid + 1;
	       else high = mid - 1;
	   }
	   return high;
	 }
    
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends
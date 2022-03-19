// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
    
        int total_sum = 0;
        for(int i=0;i<n;i++) total_sum += a[i];
        
        int left_sum = 0 , point = -1 ;
        for(int i=0;i<n;i++){
            left_sum += a[i];
            if(left_sum == total_sum){
                point = i+1;
                break;
            }
            total_sum -= a[i];
        }
        return point;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
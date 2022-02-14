// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int nonOccuringNumber = 0;
        int OccuringNumber = 0;
        int m = n + 1;
        for(int i = 0; i < n; i++){
            int val = arr[i] % m;
            arr[val - 1] += m;
        }
        for(int i = 0; i < n; i++){
            int val = arr[i];
            if((val/m) == 0){
                nonOccuringNumber = i + 1;
            }
            else if((val/m) == 2){
                OccuringNumber = i + 1;
            }
        }
        int *ans;
        ans = new int[2];
        ans[0] = OccuringNumber;
        ans[1] = nonOccuringNumber;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
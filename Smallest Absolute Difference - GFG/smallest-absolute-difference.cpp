// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(int a[] , int n ,int mid ,int k){
    int cnt = 0;
    for(int i = 0 ; i <  n; i++){
        int ind = upper_bound(a + i ,a + n ,a[i] + mid) - a;
        ind--;
        if(ind > i)
        cnt += ind - i;
    }
    return cnt >= k;
}
int kthDiff(int a[], int n, int k)
{
    sort(a, a + n);
    int l = 0 , r = a[n - 1] - a[0];
    int ans = r;
    while(l <= r){
        int mid = (l + r)/2;
        if(valid(a, n , mid , k)){
            ans = mid;
            r = mid - 1;
        }
        else 
        l = mid + 1;
    }
    return ans;
}
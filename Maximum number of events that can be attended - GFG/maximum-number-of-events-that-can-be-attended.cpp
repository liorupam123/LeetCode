// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        // code here
         vector<pair<int,int>> v;
      // inserting all the meetings in a vector
      for(int i = 0; i < N; i++)
          v.push_back({start[i],end[i]});
      
      sort(v.begin(),v.end());
      // sort all the meeting according to first and then second day
      
      priority_queue<int,vector<int>,greater<int>> pq; // min Heap
      int cnt = 0; // Max meetings
      int i = 0, d = 0;
      while(!pq.empty() || i < N){
          if(pq.size() == 0)
              d = v[i].first; // cheking if it is the first meeting
          
          /* inserting all the meetings whose starting day is smaller than
          the current day.
          */
          while(i < N && v[i].first <= d)
              pq.push(v[i++].second);
          // removing the meeting that we have taken into in our count(cnt)
          pq.pop();
          
          cnt++; // incrementing the max count
          d++; // incrementing the current day
          
          /* removing all the meetings whose ending time is smaller than d
           because those meetings can not be taken into the answer */
          while(!pq.empty() && pq.top() < d) pq.pop();
      }
      return (cnt);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
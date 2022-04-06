// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

class Solution{
public:
    int max_non_overlapping( vector< vector<int> >& ranges )
    {
        // code here
        int n=ranges.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)v[i]={ranges[i][1],ranges[i][0]};
        sort(v.begin(),v.end());
        int cnt=1;
        int strt=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>=strt){
                cnt++;
                strt=v[i].first;
                
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends
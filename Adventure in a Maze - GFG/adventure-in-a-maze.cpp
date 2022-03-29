// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
#define N 1000000007

public:
bool moveRight(int a){
   if(a == 1 || a == 3) return true;
   return false;
}

bool moveDown(int a){
   if(a != 1) return true;
   return false;
}
vector<int> FindWays(vector<vector<int>>&matrix){
    // Code here
      int n = matrix.size();
   vector< vector< pair<int, int > > > a(n, vector< pair<int, int> > (n, {0,0}));
   a[0][0].first = 1;
   for(int i = 0; i < n ; i ++){
       for(int j = 0; j < n ; j ++)
           a[i][j].second = matrix[i][j];
   }
   for(int i = 1 ; i < n ; i ++){
       if(a[0][i-1].first == 1 && moveRight(matrix[0][i-1])) {
           a[0][i].first = 1; 
           a[0][i].second += a[0][i-1].second;
       } else{
           a[0][i].first = 0;
       }
   }
   for(int j = 1; j < n ; j ++){
       if(a[j-1][0].first == 1 && moveDown(matrix[j-1][0])){
           a[j][0].first = 1;
           a[j][0].second += a[j-1][0].second;
       } else{
           a[j][0].first = 0;
       }
   }
   

   for(int i = 1; i < n ; i ++){
       for(int j = 1; j < n ; j ++){
           if(moveDown(matrix[i-1][j]) && a[i-1][j].first){
               a[i][j].first = (a[i-1][j].first)%N;
               a[i][j].second += a[i-1][j].second;
           }
           if(moveRight(matrix[i][j-1]) && a[i][j-1].first){
               a[i][j].first =( a[i][j].first%N + a[i][j-1].first%N)%N;
               a[i][j].second = max(a[i][j].second, matrix[i][j] + a[i][j-1].second);
           }
       }
   }
 
   int s1 = a[n-1][n-1].first;
   int s2 = a[n-1][n-1].second;
   if(s1 == 0) return {0, 0};
   return {s1, s2};
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
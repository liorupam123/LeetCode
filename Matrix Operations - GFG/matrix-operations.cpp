// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> a){
        //code here
         int n = a.size() , m = a[0].size() ; 
        int i = 0 , j = 0 ; 
        char dir = 'r' ;
        while(i < n and j < m  and i >= 0 and j >= 0 ) {
            switch(dir){
                case 'l' :
                if(a[i][j] == 0 ) j-- ;
                else{
                    a[i][j] = 0 ;
                    dir = 'u'  ;
                    i-- ;
                    
                }
                break ;
                case 'r' :
                if(a[i][j] == 0 ) j++ ; 
                else{
                    a[i][j] = 0 ;
                    dir = 'd'  ;
                    i++ ;
                    
                }
                break ;
                case 'd' :
                if(a[i][j] == 0 ) i++ ; 
                else{
                    a[i][j] = 0 ;
                    dir =  'l' ;
                    j-- ;
                    
                }
                break ;
                case 'u' :
                if(a[i][j] == 0 ) i-- ;
                else{
                    a[i][j] = 0 ;
                    dir = 'r'  ;
                    j++ ;
                    
                }
                break ;
            }
        }
           
            
            if(i<0 || i>=n || j<0 || j>=m)  {
          if(i >= n) i--;
          if(j >= m) j--;
          if(i < 0) i++;
          if(j < 0) j++;
            }
         return {i, j};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends
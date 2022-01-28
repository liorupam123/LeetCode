class Solution {
public:
    double knight(int n, int k, int row, int column,unordered_map<string,double>&mp){
      
        // when we are getting out of the boundary, we can't get any answer, return 0
        if(row<0 || column<0 || row>=n || column>=n)
            return 0;
        
        // here we have to take exactly k moves, so when k==0, that means we got our destination
        // return 1
        if(k <= 0)
            return 1;
        
        string currentKey = to_string(row) + "_" + to_string(column) + "_" + to_string(k);
        if(mp.find(currentKey)!=mp.end()){
            return mp[currentKey];
        }
        double sum = 0;
        
        // here the 8 directions where a knight can move
        // don't forget to moves -1 everytime
        sum = knight(n, k-1, row-2, column-1,mp) +
              knight(n, k-1, row-2, column+1,mp) +
              knight(n, k-1, row-1, column+2,mp) +
              knight(n, k-1, row+1, column+2,mp) +
              knight(n, k-1, row+2, column+1,mp) +
              knight(n, k-1, row+2, column-1,mp) +
              knight(n, k-1, row+1, column-2,mp) +
              knight(n, k-1, row-1, column-2,mp);
      
        // now calculate the avarage
        sum /= 8;
        mp[currentKey] = sum;
        return mp[currentKey];
    }
    double knightProbability(int n, int k, int row, int column) {
         unordered_map<string,double> mp;
         return knight(n, k, row, column,mp);
    }
};
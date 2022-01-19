class Solution {
public:
    int nthTribonacci(int n, vector<int>&mp){
        if(n==0){
            return 0;
        }
        
        if(n==1 || n==2){
            return 1;
        }
        
        if(mp[n]!=-1) return mp[n];
        
        int a = nthTribonacci(n-1,mp);
        int b = nthTribonacci(n-2,mp);
        int c = nthTribonacci(n-3,mp);
        
        mp[n] =  a+b+c;
        
        return mp[n] ;
    }
    int tribonacci(int n) {
        vector<int> mp(n+1,-1);
        return nthTribonacci(n,mp);
    }
};

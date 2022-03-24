class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int i=0;
        int j= p.size()-1;
        sort(p.begin(),p.end());
        int count=0;
        while(i<=j)
        {
            if(p[i]+p[j]<=limit)
            {
                count++;
                i++;
                j--;
            }
            else{
                count++;
                j--;
                
                
            }
            
        }
        return count ;
    }
};
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=s.length();
        int currCost=0;
        int low=0,high=0;
        int max_len=0;
        
        while(high<len){
            currCost+=abs(s[high]-t[high]);
            
            if(currCost>maxCost){
              while(currCost>maxCost){
                currCost-=abs(s[low]-t[low]);
                low++;
              }
            }
            else{
              max_len=max(max_len,high-low+1);
            }
            high++;
              
              
            
        }
        return max_len;
    }
    
};
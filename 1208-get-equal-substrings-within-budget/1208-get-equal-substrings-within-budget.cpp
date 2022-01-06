class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=s.length();
        int currCost=0;
        int low=0,high=0;
        int max_len=0;
        
        while(high<len){
            // calculating the cost at first
            currCost+=abs(s[high]-t[high]);
            
            // if cost > maxcost , then delete from first and move the window
            if(currCost>maxCost){
              while(currCost>maxCost){
                currCost-=abs(s[low]-t[low]);
                low++;
              }
            }
            // else , when cost<= maxcost , calculate the maximum window size
            // it is said in question then check when cost less than or equal to max cost
            else{
              max_len=max(max_len,high-low+1);
            }
            // high/j++ always to get the window/move the window
            high++;
              
        }
        return max_len;
    }
    
};
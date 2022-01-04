class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0; 
        int mx = 0;
        int k=2;
        //unordered map of the char and it's frequency 
        unordered_map<int,int> memo; 
        while(j<fruits.size()){ 
            //stroing the frequency of the character
            memo[fruits[j]]++; 
            //map size matters here, 
            //when map size <= k, store the subarray size
            //and calculate the max subarray size and move second pointer always
            if(memo.size()<=k){ 
                mx = max(mx,j-i+1); 
                j++; 
    
            }
            //when map size >k
            else if(memo.size()>k){ 
                //while(jab tak) map size > k , decrease the frequency of the characters
                while(memo.size()>k){ 
                    memo[fruits[i]]--; 
                    //when frequency of the character == 0 ,remove the char from the map
                    if(memo[fruits[i]]==0){ 
                       memo.erase(fruits[i]); 
                    } 
                    // move the first pointer to decrease / remove char from the first
                    i++; 
                } 
                //move second poiner always
                j++; 
            } 
            
        } 
        return mx; 
    }
};
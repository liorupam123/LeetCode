class Solution {
public:
    int myAtoi(string str) {
        
        stringstream obj(str); 
        int ans=0;
        obj>>ans; 
       
        return ans; 
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
       int i = a.size()-1;
        int j= b.size()-1;
        int carry =0;
        string result ="";
        while(i>=0 || j>=0 ){
            int sum =carry;
            if(i>=0) sum += a[i--]-'0';
            if(j>=0) sum += b[j--]-'0';
            
            carry = sum>1?1:0;
            result += to_string(sum%2);
           
        }
        
        if(carry) result += to_string(carry);
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};
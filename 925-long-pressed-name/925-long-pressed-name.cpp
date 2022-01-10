class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // take i and j two pointers at the first letter of word and typed
        int i = 0;
        
        // iterate through the typed string
        for (int j = 0; j < typed.size(); j++) {
            // if typed[j]==name[i], move to the next letter of name
            if ( name[i] == typed[j]) i++; 
          
            // if typed[j]!=name[i], check typed[j] with the name[i-1]
            // if typed[j]==name[i-1] , that is a long pressed
            // else it's not long pressed , return flase
            else if (i == 0 || name[i-1] != typed[j]) return false; 
        }
      
        // if i reached at the last pointer of the name, that's means all of the letters of the name
        // string is presented in typed string
        return i == name.size(); 
    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        // O(N) time , O(1) space [because hasmap size is always 3]
        int left = 0 , right = 0 , end = s.size() - 1;
        // map of char and its frequency
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(right<s.size())
        {
            map[s[right]] += 1; // adding new element to window
            
            while(map['a'] && map['b'] && map['c']) // while(window is good)
            {
                count += (end - right+1);
                
				        // removing first element[means shrinking window from front to form new window]
                map[s[left]] -= 1; 
                left++;
            }
            right++;
        }
        return count;
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        vector<string>v;
        stringstream obj(s);
        while (obj >> word) v.push_back(word);   // To push each word in vector
        
        if(pattern.size() != v.size()) return false; 
        
        unordered_map<char, string>mp;
        unordered_set<string>st;
        for(int i = 0; i < pattern.size(); i++){
            if(mp.find(pattern[i]) == mp.end()){
                if(st.find(v[i]) == st.end()){
                    mp[pattern[i]] = v[i];
                    st.insert(v[i]);
                }
                else return false;
            }
            else 
				if(mp[pattern[i]] != v[i]) return false;  
        }
        return true; 
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {  
      
        // taking a set for storing all the words from wordlist to set
        unordered_set<string> myset;
        
        // at first we are taking a false variable to check endword is present or not
        bool isPresent = false; 
        
        // iterating through all the words of wordslist
        for(auto word: wordList)
        {
            // checking if endword is present in wordlist or not
            if(endWord.compare(word)==0)
              // if present mark the false ariable as true
                isPresent = true;
            myset.insert(word); // and push all words in set  
        }
        // if the variable is still false, thats means endword is not present in the wordlist
        if(isPresent==false)   
            return 0;
        
        queue<string> q; // take a queue for bfs
        q.push(beginWord); // push the begin word into it
        int depth = 0; // depth is the answer , bfs search depthwise so..
        
        while(!q.empty())
        {
            depth+=1; // at first increament depth always
            int lsize = q.size(); // No of elements is present in the queue at a certain level
            while(lsize--)// checking still no of at a certain level becomes 0
            {
                string curr = q.front(); // always work with the first word
                q.pop();
               
                for(int i=0;i<curr.length();++i) //check for each letters of the word
                {
                    string temp = curr; // store the current word into a temp, play with the temp
                    for(char c='a';c<='z';++c) //Try to change with all possible chars from a to z
                    {
                        temp[i] = c;
                        if(curr.compare(temp)==0)
                            continue;   //Skip the same word
                      
                        // temp == endword , return depth +1
                        if(temp.compare(endWord)==0)
                            return depth+1; 
                        // new temp is present in the set
                        if(myset.find(temp)!=myset.end())  
                        {
                            // push the temp into the queue for it's change
                            q.push(temp);
                          
                            // erase the temp from the set , only one time we can use any word
                            myset.erase(temp); 
                        }
                    }
                }
            }
        }
      
        return 0; // no matching has done, return 0
    }
};
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int longestSubstring(string s) {
        // code here
        map<int, int> index;
int n=s.size();

// Initialize answer with 0
int answer = 0;

int mask = 0;
index[mask] = -1;

// Now iterate through each character
// of the string
for(int i = 0; i < n; i++)
{

// Convert the character from
// [a, z] to [0, 25]
int temp = (int)s[i] - 97;

// Turn the temp-th bit on if
// character occurs odd number
// of times and turn off the temp-th
// bit off if the character occurs
// ever number of times
mask ^= (1 << temp);

// If a mask is present in the index
// Therefore a palindrome is
// found from index[mask] to i
if (index[mask])
{
answer = max(answer,
i - index[mask]);
}

// If x is not found then add its
// position in the index dict.
else
index[mask] = i;

// Check for the palindrome of
// odd length
for(int j = 0; j < 26; j++)
{

// We cancel the occurrence
// of a character if it occurs
// odd number times
int mask2 = mask ^ (1 << j);
if (index[mask2])
{
answer =max(answer,
i - index[mask2]);
}
}
}
return answer;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
    }
    return 0;
}  // } Driver Code Ends
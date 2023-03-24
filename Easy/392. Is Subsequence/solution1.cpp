// This solution runs in O(n) time and has O(1) space complexity. It keeps track of the main string t, and the substring s. While iterating through string t, 
// it increments our place in s if we find the letter we need. If we reach the end of s, we found the subsequence. 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (t[i] && s[j]) {
            if (s[j] == t[i]) { // found character in subsequence
                j++;
            }
            i++;
        }
        if (s[j]) { // did not find the subsequence
            return false;
        }
        return true;
    }
};
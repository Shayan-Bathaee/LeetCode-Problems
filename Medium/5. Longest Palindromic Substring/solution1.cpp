// This solution runs in O(n^2) time. I'm not super proud of this solution, because it feels really hacky and I'm sure there's a cleaner (and faster) recursive 
// implementation. checkPalindrome figures out the longest palindrome that can be made with a specific index in the middle. It does this by stepping left and right 
// from that character and verifying that the characters are equal. There is a bit of additional complexity required there due to the fact that there can be even or odd
// palindromic substrings. The longestPlaindrome function simply runs checkPalindrome for each character, and returns the longest palindromic substring it found. 

class Solution {
public:
    // find the longest palindrome within a string
    string longestPalindrome(string s) {
        int resultLength = 1;
        int resultStart = 0;
        
        for (int i = 0; i < s.length(); i++) { // for every character
            int newLength = checkPalindrome(s, i); // get length of longest palindrome w/ character in middle
            if (newLength > resultLength) { // update resultLength and resultStart
                resultLength = newLength;
                if (newLength % 2 == 0) { // even length
                    resultStart = i - ((newLength / 2) - 1);
                }
                else {
                    resultStart = i - (newLength / 2);
                }
            }
        }
        
        string result = s.substr(resultStart, resultLength);
        return result;
    }
    
    // helper funciton to check what the longest palindrome is with a specific character in the middle
    int checkPalindrome(string s, int i) {
        // case 1: first character in the string
        if (i == 0) {
            return (s[i] == s[i + 1]) ? 2 : 1;
        }
        
        // case 2: any other character
        int lengthOdd = 1; // num characters in palindrome are odd
        int lengthEven = 0; // num characters in palindrome are even
        // check length odd
        int left = i - 1;
        int right = i + 1;
        while ((left > -1) && (s[left] == s[right])) {
            lengthOdd += 2;
            left -= 1;
            right += 1;
        }
        // check length even
        left = i;
        right = i + 1;
        while ((left > -1) && (s[left] == s[right])) {
            lengthEven += 2;
            left -= 1;
            right += 1;
        }
        
        // return the greater value
        return max(lengthOdd, lengthEven);
    }
}; 
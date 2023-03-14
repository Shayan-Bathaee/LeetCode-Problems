// This solution runs in O(n) time and has O(n) space complexity. First, it converts the integer into a string. By doing so, we can index the 
// front and back of the string and compare the values, closing in on the middle of the string with each iteration. If every value is equal
// on both sides, we have a palindrome. 

class Solution {
public:
    bool isPalindrome(int x) {
        string strx = to_string(x);
        int backIndex = strx.length() - 1;
        int frontIndex = 0;
        while (backIndex > frontIndex) {
            if (strx[backIndex] != strx[frontIndex]) {
                return false;
            }
            backIndex -= 1;
            frontIndex += 1;
        }
        return true;
    }
};
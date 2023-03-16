// This solution runs in O(n) time and has O(1) space complexity. The algorithm works by simply looping through the string and incrementing/decrementing the 
// variable 'total' which gets returned at the end. We start out by initializing a map of roman characters to their values, and then using that map to get the 
// integer value of each character in the string s. If the character after is greater, we need to decrement, else, we increment. 


class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int strLen = s.length();
        int total = 0; // contains return val

        // for every character except for the last character
        for (int i = 0; i < strLen; i++) {
            // if we are at the last char, add it and return
            if (i == (strLen - 1)) {
                total += romanMap[s[i]];
                return total;
            }
            
            // else, determine what value to add
            int currentCharVal = romanMap[s[i]];
            int nextCharVal = romanMap[s[i + 1]];
            if (currentCharVal < nextCharVal) { // if our current character is less than the next one, add the difference and skip over the next char
                total += nextCharVal - currentCharVal;
                i += 1;
            } else {
                total += currentCharVal; // else add the character
            }
        }
        return total;
        
    }
};
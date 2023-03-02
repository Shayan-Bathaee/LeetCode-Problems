// This solution runs in O(n^2) time. It figures out the longest substring with unique characters at every index in the string, and returns the longest one of all.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int current_length = 0;
        int best_length = 0;
        for (int i = 0; i < s.length(); i++) { // for every character in s
            int sub_index = i;
            string current_string = "";
            current_length = 0;
            while (s[sub_index]) { // start new substring at the current index
                // get all unique characters 
                if (current_string.find(s[sub_index]) != string::npos) { // we already have this character
                    break;
                }
                else { // we don't already have this character
                    current_string += s[sub_index]; // add it to our string and update length
                    current_length += 1;
                }
                sub_index += 1;
            }
            best_length = max(current_length, best_length); // update best length
        }
        return max(current_length, best_length);
    }
};
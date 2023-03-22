// This solution runs in O(n^2) time and has O(n) space complexity. I'm not a big fan of this implementation because I think I could do a
// recursive version that would look cleaner, and the time/space complexity if it is no good. This is definitely a brute force solution.
// But it works tho B)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> conversions;
        int i = 0;
        while (s[i] && t[i]) {
            if (conversions.find(s[i]) != conversions.end()) { // if character is in conversion map
                if (conversions[s[i]] == t[i]) { // check if the conversion is correct
                    i++;
                }
                else {
                    return false;
                }
            }
            else { // character is not in the conversion map
                // make sure t[i] isn't already being used
                for (int j = 0; j < i; j++) {
                    if (conversions[s[j]] == t[i]) {
                        return false;
                    }
                }
                conversions[s[i]] = t[i];
                i++;
            }
        }
        return true; // reached end of strings and everything worked
    }
};
// This solution runs in linear time. I implemented the solution by following the basic steps provided in the description of the problem.
// I'm not particularly proud of this solution. It looks really ugly IMO, but I think that might be because of all the edge cases that 
// need to be considered for the problem. A lot of times when I program, I just get deep into the logical flow of the problem, and this is
// definitely an example of that. 

#define UPPER_BOUND 2147483647 // 2^31 - 1
#define LOWER_BOUND -2147483648 // -(2^31)

class Solution {
public:
    int myAtoi(string s) {
        int i = 0; // main index
        
        // step 1: ignore leading whitespace
        while (s[i] == ' ') {
            i++;
        }
        
        // step 2: figure out if the next character is a + or - 
        bool negative = false;
        if (s[i] == '-') {
            negative = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        
        // step 3: read in the next characters until non digit character or end of string
        string numberString = "";
        while ((s[i] > 47) && (s[i] < 58)) { // check they are digits using ascii values
            numberString += s[i];
            i++;
        }
        
        // step 4: convert these digits into an integer
        i = 0; // new main index for numberString
        while (numberString[i] == '0') {
            i++;
        }
        numberString.erase(0, i); // erase leading zeros
        
        if (numberString == "") { // no digits remain
            return 0;
        }

        if (numberString.length() > 11) { // string is too long to be in our bounds
            if (negative) {
                return LOWER_BOUND;
            }
            return UPPER_BOUND;
        }
        
        long long int numberLong = stoll(numberString, NULL, 10);
        if (negative) {
            numberLong *= -1;
        }
        
        // step 5: clamp integer if it is too big or too small
        if (numberLong < LOWER_BOUND) {
            return LOWER_BOUND;
        }
        else if (numberLong > UPPER_BOUND) {
            return UPPER_BOUND;
        }
        else {
            return numberLong;
        }
    }
};
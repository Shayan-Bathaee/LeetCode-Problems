// This solution runs in O(n + k) time, where n is the size of string s and k is numRows. It's space complexity is O(n). 
// The solution works by creating a vector to store each row of the zigzag string. The algorithim fills in that vector by keeping track of 
// the row we are on and whether or not we are going up or going down in the zigzag. 

class Solution {
public:
    string convert(string s, int numRows) {
        // base case, numRows = 1
        if (numRows == 1) {
            return s;
        }
        
        // create a vector of numRows empty strings to store each row
        vector<string> rows(numRows, "");
        
        // fill in the rows using zigzag algorithm
        int row = 0;
        int goingUp = false;
        for (int i = 0; i < s.length(); i++) {
            rows[row] += s[i];
            if (goingUp) { 
                if (row == 0) { // reached top row, time to go down
                    goingUp = false;
                    row = 1;
                }
                else { // go up one row
                    row -= 1;
                }
            }
            else { // we are going down
                if (row == numRows - 1) { // reached bottom row, time to go up
                    goingUp = true;
                    row = numRows - 2;
                }
                else { // go down one row
                    row += 1;
                }
            }
        }
        
        // return the result string
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }
        
        return result;
    }
};
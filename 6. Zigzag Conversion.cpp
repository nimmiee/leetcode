class Solution {
public:
    string convert(string s, int numRows) {
         // Base case: If numRows is 1 or less, return the original string
        if (numRows <= 1) {
            return s;
        }
        
        // Initialize an array of strings to represent rows
        vector<string> rows(min(numRows, int(s.length())));
        int curRow = 0; // Current row
        bool goingDown = false; // Direction of movement
        
        // Iterate through the characters of the original string
        for (char c : s) {
            // Add the character to the current row
            rows[curRow] += c;
            
            // Update the current row and direction of movement
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            if (goingDown) {
                curRow++;
            } else {
                curRow--;
            }
        }
        
        // Concatenate characters in each row to form the zigzag pattern
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
    
};
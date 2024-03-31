class Solution {
public:
    int reverse(int x) {
           int result = 0;
        
        // Handle negative numbers by remembering the sign
        bool isNegative = x < 0;
        // Convert x to its absolute value
        long long absX = llabs((long long)x);
        
        // Reverse the digits of absX
        while (absX > 0) {
            // Extract the last digit of absX
            int digit = absX % 10;
            // Check for overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return 0; // Overflow occurred, return 0
            }
            // Append the digit to result
            result = result * 10 + digit;
            // Remove the last digit from absX
            absX /= 10;
        }
        
        // Restore the sign if x was negative
        if (isNegative) {
            result = -result;
        }
        
        return result;
    
    }
};
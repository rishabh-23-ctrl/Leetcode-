class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--;  // adjust for 1-based indexing
            
            int rem = columnNumber % 26;
            result += (char)('A' + rem);
            
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
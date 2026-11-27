class Solution {
public:
    bool validDigit(int n, int x) {
        int digit = 0;
        bool valid = false;
        while(n != 0){
            digit = n % 10;
            if(digit == x) valid = true;
            n /= 10;
        }
        if(digit != x && valid) return true;
        return false;
    }
};
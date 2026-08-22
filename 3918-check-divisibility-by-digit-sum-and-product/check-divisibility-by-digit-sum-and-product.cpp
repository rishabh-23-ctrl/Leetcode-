class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1, total = 0;
        int num = n;
        while(num != 0){
            int digit = num % 10;
            sum += digit;
            product *= digit;
            num /= 10;
        }
        total = sum + product;
        if(n % total == 0) return true;
        else return false;
    }
};
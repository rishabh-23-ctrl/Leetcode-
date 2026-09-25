class Solution {
public:
    int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long a = dividend;
        long long b = divisor;

        // Determine the sign
        bool negative = (a < 0) ^ (b < 0);

        // Work with positive values
        a = abs(a);
        b = abs(b);

        long long ans = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Find the largest multiple of divisor
            // that can be subtracted from dividend
            while ((temp << 1) <= a) {
                temp = temp << 1;
                multiple = multiple << 1;
            }

            a -= temp;
            ans += multiple;
        }

        if (negative) {
            ans = -ans;
        }

        return (int)ans;
    }
};
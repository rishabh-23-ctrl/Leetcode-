class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                // Prevent product overflow
                if (product > LLONG_MAX / x)
                    break;

                product *= x;
                g = gcd(g, (long long)x);

                long long common = gcd(l, (long long)x);

                // Prevent LCM overflow
                if (l / common > LLONG_MAX / x)
                    break;

                l = (l / common) * x;

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    const int MOD = 1e9 + 7;

    int subsequenceSum(string &s) {
        long long sum = 0;

        for (char c : s) {
            sum += (c - '0');
        }

        long long power = 1;
        long long base = 2;
        int exp = s.size() - 1;

        // Calculate 2^(n-1) % MOD
        while (exp > 0) {
            if (exp & 1)
                power = (power * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return (sum % MOD * power) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
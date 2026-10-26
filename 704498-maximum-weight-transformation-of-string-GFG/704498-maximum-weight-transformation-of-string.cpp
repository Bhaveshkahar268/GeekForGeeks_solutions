
class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.size();
        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Keep s[i] as a single character
            dp[i] = 1 + dp[i + 1];

            // Option 2: Form a pair with the next character
            if (i + 1 < n) {
                int pairWeight = (s[i] != s[i + 1]) ? 4 : 3;
                dp[i] = max(dp[i],
                            pairWeight + dp[i + 2]);
            }
        }

        return dp[0];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
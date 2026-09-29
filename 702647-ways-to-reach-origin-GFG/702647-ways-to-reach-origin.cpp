class Solution {
public:
    int ways(int x, int y) {
        const int MOD = 1000000007;

        vector<vector<long long>> dp(x + 1, vector<long long>(y + 1));

        // Base cases
        for (int i = 0; i <= x; i++)
            dp[i][0] = 1;

        for (int j = 0; j <= y; j++)
            dp[0][j] = 1;

        // DP
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[x][y];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
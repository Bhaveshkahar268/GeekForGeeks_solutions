class Solution {
public:
    int getMinimumDays(string &s, vector<int> &p) {
        int n = s.size();

        vector<int> pos(n);

        // Find the day on which each index is replaced.
        for (int i = 0; i < n; i++) {
            pos[p[i]] = i + 1;
        }

        int ans = 0;

        // Check every adjacent pair.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                ans = max(ans, min(pos[i], pos[i + 1]));
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
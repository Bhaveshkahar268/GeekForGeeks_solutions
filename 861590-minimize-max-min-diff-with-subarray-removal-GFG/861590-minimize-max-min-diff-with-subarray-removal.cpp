class Solution {
public:
    int minDiff(int k, vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixMin(n), prefixMax(n);
        vector<int> suffixMin(n), suffixMax(n);

        prefixMin[0] = prefixMax[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i - 1], arr[i]);
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }

        suffixMin[n - 1] = suffixMax[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], arr[i]);
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n - k; i++) {
            int j = i + k - 1;

            int mn = INT_MAX, mx = INT_MIN;

            if (i > 0) {
                mn = min(mn, prefixMin[i - 1]);
                mx = max(mx, prefixMax[i - 1]);
            }

            if (j < n - 1) {
                mn = min(mn, suffixMin[j + 1]);
                mx = max(mx, suffixMax[j + 1]);
            }

            if (mn != INT_MAX) {
                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
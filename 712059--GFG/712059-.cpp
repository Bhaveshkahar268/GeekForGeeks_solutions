class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        long long sum = 0;
        int l = 0, ans = 1;

        for (int r = 0; r < arr.size(); r++) {
            sum += arr[r];

            while (1LL * arr[r] * (r - l + 1) - sum > k) {
                sum -= arr[l++];
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
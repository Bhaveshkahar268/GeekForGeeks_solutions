class Solution {
public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (a % 2 == b % 2)
                return (a % 2) ? a > b : a < b;
            else
                return a % 2 == 1;
        });
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
  public:
    int minOperation(int n) {
        // code here
        return __builtin_popcount(n)+ log2(n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
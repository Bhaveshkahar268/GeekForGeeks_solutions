class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        int res = 0;
        for(auto vec : adj)
        res += vec.size();
        return res/2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
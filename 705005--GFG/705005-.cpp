class Solution {
public:
    int minSquares(int n, int m) {

        int res = 0;

        pair<int, int> p{min(m, n), max(m, n)};

        while (p.first) {
            res += (p.second / p.first);
            p = {min(p.second % p.first, p.first),
                 max(p.second % p.first, p.first)};
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
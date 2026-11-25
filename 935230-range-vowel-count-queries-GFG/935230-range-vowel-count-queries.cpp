
class Solution {
public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = s.size();

        vector<int> prefix(n + 1, 0);

        // Build prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];

            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                prefix[i + 1]++;
            }
        }

        vector<int> ans;

        // Answer each query
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ans.push_back(prefix[r + 1] - prefix[l]);
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
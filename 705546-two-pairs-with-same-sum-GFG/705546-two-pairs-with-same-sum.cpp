
class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();

        unordered_map<long long, vector<pair<int, int>>> mp;

        // Store all index pairs according to their sum
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long sum = 1LL * arr[i] + arr[j];
                mp[sum].push_back({i, j});
            }
        }

        // Check pairs in lexicographical order
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {

                long long sum = 1LL * arr[a] + arr[b];

                auto itMap = mp.find(sum);

                if (itMap == mp.end())
                    continue;

                auto &v = itMap->second;

                // Second pair must be lexicographically greater
                auto it = lower_bound(
                    v.begin(), v.end(),
                    make_pair(a + 1, -1)
                );

                while (it != v.end()) {

                    int c = it->first;
                    int d = it->second;

                    // Skip pairs sharing an index
                    if (c == b) {
                        it = lower_bound(
                            v.begin(), v.end(),
                            make_pair(b + 1, -1)
                        );
                        continue;
                    }

                    if (d == b) {
                        ++it;
                        continue;
                    }

                    return {a, b, c, d};
                }
            }
        }

        return {-1, -1, -1, -1};
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
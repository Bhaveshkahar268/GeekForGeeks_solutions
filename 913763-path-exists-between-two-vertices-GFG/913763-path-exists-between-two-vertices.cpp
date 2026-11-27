
class Solution {
public:
    bool checkPath(vector<vector<int>>& adj, int u, int v) {
        int n = adj.size();
        vector<bool> vis(n, false);

        function<bool(int)> dfs = [&](int node) {
            if (node == v) return true;

            vis[node] = true;

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    if (dfs(neighbor))
                        return true;
                }
            }

            return false;
        };

        return dfs(u);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna

class Solution {
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    long long unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return 0;

        if (sz[u] < sz[v])
            swap(u, v);

        long long paths = 1LL * sz[u] * sz[v];

        parent[v] = u;
        sz[u] += sz[v];

        return paths;
    }

public:
    vector<int> maximumWeight(int n,
                             vector<vector<int>>& edges,
                             vector<int>& queries) {

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        // Store queries with their original indices
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        long long cnt = 0;
        int j = 0;

        // Process queries in increasing order
        for (auto &query : q) {
            int x = query.first;
            int idx = query.second;

            // Add all edges with weight <= x
            while (j < edges.size() && edges[j][2] <= x) {
                cnt += unite(edges[j][0], edges[j][1]);
                j++;
            }

            ans[idx] = (int)cnt;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
public:
    int X[4] = {1, 0, -1, 0};
    int Y[4] = {0, 1, 0, -1};

    pair<pair<int,int>, int> nextMove(int i, int j, int move,
                                      int n, vector<vector<bool>>& visited) {
        int N = 4 * n;

        for (int k = 0; k < 4; k++) {
            int d = (move + k) % 4;
            int ni = i + X[d], nj = j + Y[d];

            if (ni >= 0 && nj >= 0 && ni < N && nj < N &&
                !visited[ni][nj])
                return {{ni, nj}, d};
        }

        return {{-1, -1}, -1};
    }

    vector<vector<int>> formCoils(int n) {
        int N = 4 * n;
        vector<vector<bool>> visited(N, vector<bool>(N));

        queue<pair<pair<int,int>,int>> q;
        q.push({{0, 0}, 0});
        q.push({{N-1, N-1}, 2});

        visited[0][0] = true;
        visited[N-1][N-1] = true;

        vector<int> first, second;

        while (!q.empty()) {
            auto [c1, m1] = q.front(); q.pop();
            auto [c2, m2] = q.front(); q.pop();

            first.push_back(c1.first * N + c1.second + 1);
            second.push_back(c2.first * N + c2.second + 1);

            auto [nc1, nm1] = nextMove(c1.first, c1.second, m1, n, visited);
            auto [nc2, nm2] = nextMove(c2.first, c2.second, m2, n, visited);

            if (nm1 == -1 || nm2 == -1) break;

            visited[nc1.first][nc1.second] = true;
            visited[nc2.first][nc2.second] = true;

            q.push({nc1, nm1});
            q.push({nc2, nm2});
        }

        return {first, second};
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
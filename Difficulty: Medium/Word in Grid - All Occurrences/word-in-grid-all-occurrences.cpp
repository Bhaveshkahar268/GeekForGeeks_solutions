class Solution {
  public:
    bool isValid(int x, int y, int n, int m){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    bool searchFrom(int x, int y, vector<vector<char>>& grid, string& word, int dx, int dy){
        int n = grid.size(), m = grid[0].size(), len = word.length();
        for(int i = 0; i < len; i++){
            int nx = x + i * dx;
            int ny = y + i * dy;
            if(!isValid(nx, ny, n, m) || grid[nx][ny] != word[i])
                return false;
        }
        return true;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        vector<vector<int>> res;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == word[0]){
                        for(int x = -1; x <= 1; x++){
                            for(int y = -1; y <= 1; y++){
                                if( x == 0 && y == 0)   continue;
                                if(searchFrom(i, j, grid, word, x, y)){
                                    res.push_back({i, j});
                                    x = y = 2;    // early exit
                                }
                            }
                        }
                }
            }
        }
        return res;
    }
};
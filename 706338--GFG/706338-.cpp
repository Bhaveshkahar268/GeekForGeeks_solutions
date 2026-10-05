class Solution {
  public:
    int X[4]={-1, 0, 1, 0};
    int Y[4]={0, 1, 0, -1};

    virtual int svc(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp){


      if(dp[i][j] != -1) return dp[i][j];

      int opt=1;
      for(int k=0; k<4; k++){
        int ni=i+X[k];  
        int nj=j+Y[k];

        if(ni<0 || nj<0 || ni>=n || nj>=m || (matrix[ni][nj]<=matrix[i][j])) continue;
        opt = max(opt, 1 + svc(ni, nj, matrix, n, m, dp));

      }

      return dp[i][j]=opt;
    }

    virtual int longIncPath(vector<vector<int>> &matrix, int n, int m){
      vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

      int ans=0;

      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          ans=max(ans, svc(i, j, matrix, n, m, dp));        
        }  
      }

      return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
  public:
    virtual int lcsUtil(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
      if(i<0 || j<0) return 0;
      if(dp[i][j] != -1) return dp[i][j];

      if(s1[i]==s2[j]) return dp[i][j]=1+lcsUtil(i-1, j-1, s1, s2, dp);
      return dp[i][j]=max(lcsUtil(i-1, j, s1, s2, dp), lcsUtil(i, j-1, s1, s2, dp));
    }

    virtual int findMinCost(string &s1, string &s2, int costS1, int costS2){
      int n1=s1.size(), n2=s2.size();

      vector<vector<int>> dp(n1, vector<int>(n2, -1));

      int lcsLen = lcsUtil(n1-1, n2-1, s1, s2, dp);

      return (costS1*(n1-lcsLen) + costS2*(n2-lcsLen));

    }
};
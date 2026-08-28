class Solution {
  public:
    int countSubsequences(string& s, int n) {
        // code here
        vector<vector<int>> dp(s.length(),vector<int>(n,-1));
        return solve(s,n,0,0,dp); 
    }
    long long solve(string& s, int N, int i, int rem, vector<vector<int>>& dp) {

        if(i==s.length()) {
            return 0;
        }
        if(dp[i][rem]!=-1) {
            return dp[i][rem];
        }
        long long a=(rem*10+(s[i]-'0'))%N, b=0, c=0, d=0;
        if(a==0) {
            b=1+solve(s,N,i+1,a,dp);
        }
        else {
            c=solve(s,N,i+1,a,dp);
        }
        d=solve(s,N,i+1,rem,dp);

        return dp[i][rem]=(b+c+d)%1000000007;
    }
};
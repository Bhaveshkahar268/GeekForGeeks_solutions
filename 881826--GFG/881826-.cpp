class Solution {
  public:
  #define ll long long
  #define INF -1e18
  ll dp[100004][2][3];
  int n;
  vector<int>   nums ; 
  ll f(int i,int op,int ok){
      if(i>=n || (ok==0))  return 0 ;
      if(dp[i][op][ok+1]!=-1  )   return dp[i][op][ok+1] ; 
      ll ans = INF ;
      ll x =  nums[i];
      if(ok==-1) {
          //skip
          ll tt = f(i+1,op,-1);
          if(tt!=INF) ans=max(ans,tt);

          //take but no op
          tt = f(i+1,op,1);
          if(tt!=INF) ans=max(ans,x + tt);

          // take and sqr

           if(op>=1){
                tt = f(i+1,0,1);
                if(tt!=INF) ans=max(ans,1LL*x*x + tt);
           }

      }
      else if(ok==1){
          //chalu che

          //chalu rakho with no op
            ll tt = f(i+1,op,1);
            if(tt!=INF) ans=max(ans,x + tt);

          //chalu with op


           if(op>=1){
                tt = f(i+1,0,1);
                if(tt!=INF) ans=max(ans,1LL*x*x + tt);
           }

           //bnd kro

            tt = f(i+1,op,0);
            if(tt!=INF) ans=max(ans, tt);


      }

      return dp[i][op][ok+1] = ans ; 

  }
    int maximumSubarray(vector<int>& arr) {
        // code here
        n=arr.size();
        nums = arr ;
        memset(dp,-1,sizeof(dp));
        return f(0,1,-1) ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
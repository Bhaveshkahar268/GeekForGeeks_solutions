class Solution {
  public:
    virtual int minSubarraySum(vector<int> &arr){
      int ans=INT_MAX;

      int c=0;
      for(int x: arr){
        c+=x;
        ans=min(c, ans);
        if(c>0) c=0;
      }

      return ans;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
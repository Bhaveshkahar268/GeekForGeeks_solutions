class Solution {
  public:
    int maxValue(int n) {
        // code here
        int ans=0;
                int i=31;
                int count=0;
                while(i>=0)
                {
                    if(count<=1 && (n&(1<<i)))
                    {
                        ans=(ans|(1<<i));
                        count++;
                    }
                    else
                    {
                        count=0;
                    }
                    i--;
                }
                return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
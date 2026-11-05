class Solution {
  public:
    long long int countBT(int h) { 
        long long int mod=1000000007;
        long long int a=1;
        long long int b=1;
        long long int c;
        for(int i=2;i<=h;i++){
            c =b*((2*a)+b)%mod;
            a=b;
            b=c;
        }
        return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
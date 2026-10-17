class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int cnt = 0;

        while(n != 0) {
            if(n%3 == 0) {
                cnt++;
                n = n/3;
            }
            else {
                cnt++;
                n = n-1;
            }
        }

        return cnt-1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
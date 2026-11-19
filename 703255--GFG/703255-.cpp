class Solution {
  public:
    int minFlips(string &s) {
        int n = s.length();
        int k = 1, cnt1 = 0, cnt0 = 0;
        for(int i = 0;i<n;i++){
            if(k != int(s[i]-'0')){
                cnt1++;
            }
            k = (k + 1)%2;
        }
        k = 0;
        for(int i = 0;i<n;i++){
            if(k != int(s[i]-'0')){
                cnt0++;
            }
            k = (k + 1)%2;
        }
        return min(cnt1, cnt0);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
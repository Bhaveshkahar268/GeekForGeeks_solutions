class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int n = arr.size();

        int i = 0, j = 0;
        int maxi = INT_MAX;
        int sum = 0;
        int result = 0;

        while(i < n && j < n){
            sum = sum + arr[i];
            while(sum > x){

                if(sum > x ){

                    maxi = min(maxi, i - j + 1);
                    result = maxi;
                }
                sum = sum - arr[j];
                j++;

            }

            i++;
        }
        return result;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {

        int n = arr.size();

           if (n == 0)
               return 0;


           vector<int> leftMax(n);


           leftMax[0] = arr[0];


           for (int i = 1; i < n; i++)
               leftMax[i] =  max(leftMax[i - 1], arr[i]);
           int rightMin = arr[n - 1];
           int count = 0;


           if (arr[n - 1] == leftMax[n - 1])
               count++;


           for (int i = n - 2; i >= 0; i--)
           {
               if (arr[i] == leftMax[i] && arr[i] < rightMin)
                   count++;
               rightMin = min(rightMin, arr[i]);
           }

           return count;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
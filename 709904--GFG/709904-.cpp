class Solution {
public:
    vector<int> lexicographicallyLargest(vector<int>& arr) {
        int i = 0;
        int n = arr.size();

        while (i < n) {

            bool odd = (arr[i] % 2);
            int j = i + 1;

            while ((j < n) && ((arr[j] % 2) == odd))
                j++;

            sort(arr.begin() + i, arr.begin() + j, greater<int>());
            i = j;
        }
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
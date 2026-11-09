class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();++i)
        {
            map[arr[i]]++;
            if(map[arr[i]]==k) return arr[i];
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
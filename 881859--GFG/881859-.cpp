class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();
        string t = s + s;
        int i = 0;
        int j = 1;
        int k = 0;
        while(i < n && j < n && k < n) {
            if(t[i + k] == t[j + k]) {
                k++;
                continue;
            }
            if(t[i + k] > t[j + k])
                i = i + k + 1;
            else
                j = j + k + 1;

            if(i == j)
                j++;

            k = 0;
        }
        int start = min(i, j);
        return t.substr(start, n);
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
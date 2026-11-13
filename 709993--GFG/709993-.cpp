class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here

        int x = s1.size();
        int y = s2.size();
        int z = s3.size();


        int maxi = 0;

        unordered_set<int>set1;
         unordered_set<int>set2;

        int sum = 0;


        for(int i=x-1; i>=0; i--){

            sum+= s1[i];

            set1.insert(sum);
        }


          sum = 0;
        for(int i=y-1; i>=0; i--){

            sum+= s2[i];

            set2.insert(sum);
        }


        sum = 0;

        for(int i=z-1; i>=0; i--){

            sum+= s3[i];

            if(set1.count(sum) && set2.count(sum)){

                maxi = max(maxi, sum);
            }
        }

        return maxi;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
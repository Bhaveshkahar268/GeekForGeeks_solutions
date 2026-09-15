class Solution {
  public:
    virtual int dominantPairs(vector<int> &arr){
      int n=arr.size();
      int n_2 = n/2;

      sort(arr.begin(), arr.begin()+n_2);
      sort(arr.begin()+n_2, arr.end());

      int count=0;
      for(int i=n_2; i<n; i++){
        int x=5*arr[i];

        int f_i = lower_bound(arr.begin(), arr.begin()+n_2, x) - arr.begin();

        if(!(f_i < n_2)) return count;
        else count+=(n_2 - f_i);
      }

      return count;

    }
};
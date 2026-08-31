class Solution {
  public:
    const int mod = 1e9+7; 
    long long nPr(int k ,int len){
        long long ans = 1;
       for(int i=0;i<len;i++){
           ans  = (ans*(k-i))%mod;
       }
       return ans;
    }
    int palindromicStrings(int n, int k) {
        // code here

        long long ans=0;

        for(int i=1;i<=n;i++){
            int len = (i+1)/2;

            if(len>k) continue;
            long long cnt = nPr(k,len);

            ans= (ans+cnt)%mod;


        }
        return ans ;
    }
};
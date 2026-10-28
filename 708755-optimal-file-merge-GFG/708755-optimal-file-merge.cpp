class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i=0; i<files.size(); i++){
            pq.push(files[i]);
        }
        int ans= 0;
        while(!pq.empty() and pq.size()>1){
            int top1= pq.top();
            pq.pop();
            int top2= pq.top();
            pq.pop();
            int total= top1+ top2;
            pq.push(total);
            ans+= total;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
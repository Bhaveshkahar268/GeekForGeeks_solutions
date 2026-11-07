class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        //x -> no of tasks that go to s1

        if(s1 > s2) swap(s1, s2); //assume s1 is faster

        //time taken = max(x*s1, (n-x)*s2) = max(y1, y2)
        //draw graph of y1 and y2, their intersection(solve linear eqns y1 and y2 simultaneously) gives
        //minimum maximum point which can be non-integer so take
        //floor and ceiling val

        int x1 = n*s2/(s1+s2); //floor val
        int x2 = (n*s2 + s1 + s2 - 1)/(s1 + s2); //ceil val

        return min(max(x1*s1, (n-x1)*s2), max(x2*s1, (n-x2)*s2));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
class Solution {
  public:
    bool findPattern(string& s) {
        // code here

        int i=0;
       while(i<s.length()){

           int x=0;
           int y=0;

           while(i<s.length() and s[i]=='x'){ //count x
               x++;
               i++;
           }

           while(i<s.length() and s[i]=='y'){//count y
               y++;
               i++;
           }


           if(x!=y) return false;     // condition  
       }

       return true; 

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
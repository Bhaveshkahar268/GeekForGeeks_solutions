/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void f(Node* root, vector<int> &arr){
        if(root == NULL) return ;
        f(root->left, arr) ; arr.push_back(root->data) ;
        f(root->right, arr) ;
    }
    int minDiff(Node *root, int k) {

        vector<int> arr ; f(root, arr) ; int n = arr.size() ;
        int mn = INT_MAX ;
        for(int i=0;i<n;i++){
            int x = abs(k-arr[i]) ;
            mn = min(mn, x) ;
        }
        return mn ;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
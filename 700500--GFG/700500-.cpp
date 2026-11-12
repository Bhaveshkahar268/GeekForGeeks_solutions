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
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> ans;
        stack<Node*> s1, s2;

        while (r1 || r2 || !s1.empty() || !s2.empty()) {

            while (r1) {
                s1.push(r1);
                r1 = r1->left;
            }

            while (r2) {
                s2.push(r2);
                r2 = r2->left;
            }

            if (s1.empty() || s2.empty())
                break;

            Node* n1 = s1.top();
            Node* n2 = s2.top();

            if (n1->data == n2->data) {
                ans.push_back(n1->data);

                s1.pop();
                s2.pop();

                r1 = n1->right;
                r2 = n2->right;
            }
            else if (n1->data < n2->data) {
                s1.pop();
                r1 = n1->right;
            }
            else {
                s2.pop();
                r2 = n2->right;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
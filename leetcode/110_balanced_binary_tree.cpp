#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeightAndBalance(root, 0) != -1;
    }

    int checkHeightAndBalance(TreeNode* n, int prev_height) {
        if (!n) {
            return prev_height;
        } else {
            int l_height = checkHeightAndBalance(n->left, prev_height+1);
            if (l_height == -1) {
                return -1;
            }
            int r_height = checkHeightAndBalance(n->right, prev_height+1);
            if (r_height == -1) {
                return -1;
            }
            if (abs(l_height - r_height) > 1) {
                return -1;
            }
            return max(l_height, r_height);
        }
    }
};


int main() {
    
}
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * [low, high]
     */
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        int v = root->val;
        if (v >= low && v <= high) {
            return v + rangeSumBST(root->left, low, high) +
                       rangeSumBST(root->right, low, high);
        } else if (v < low) {
            return v + rangeSumBST(root->right, low, high);
        } else {
            return v + rangeSumBST(root->left, low, high);
        }
    }
};
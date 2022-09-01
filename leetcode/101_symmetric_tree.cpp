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
    bool isSymmetric(TreeNode* root) {
        return areSymmetricSubtrees(root->left, root->right);
    }

    bool areSymmetricSubtrees(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        } else if (!a || !b) {
            return false;
        } else if (a->val != b->val) {
            return false;
        } else {
            return areSymmetricSubtrees(a->left, b->right)
                    && areSymmetricSubtrees(a->right, b->left);
        }
    }
};
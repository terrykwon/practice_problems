
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Naive O(n*m) solution.
        // There exists a O(n) solution where the (inorder, preorder) traversal
        // arrays of both trees are compared.
        if (!root) {
            return false;
        } else if (isSameTree(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot)
                || isSubtree(root->right, subRoot);
        }
    }

    bool isSameTree(TreeNode* a, TreeNode* b) {
        // Return true if the trees rooted at a and b are *exactly* the same.
        if (!a && !b) {
            return true;
        } else if (!a || !b) {
            return false;
        }

        return a->val == b->val &&
                isSameTree(a->left, b->left) && 
                isSameTree(a->right, b->right);
    }
};
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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p = heightAndDiameter(root);
        return p.second;
    }

    pair<int, int> heightAndDiameter(TreeNode* n) {
        if (!n) {
            return {-1, -2};
        }

        pair<int, int> p1 = heightAndDiameter(n->left);
        pair<int, int> p2 = heightAndDiameter(n->right);

        int height_l = p1.first;
        int height_r = p2.first; 
        int diameter_l = p1.second;
        int diameter_r = p2.second;

        int height_n = max(height_l, height_r) + 1;
        int diameter_n = max({height_l+height_r+2, diameter_l, diameter_r});

        return {height_n, diameter_n};
    }
};
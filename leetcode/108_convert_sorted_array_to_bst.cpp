#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayRangeToBST(nums, 0, nums.size());
    }

    /**
     * l: inclusive, r: exclusive
     * if length 1: [1, 2) -> m=1 -> [1,1), [2,2) -> 1 is correctly excluded
     * if length 2: [1, 3] -> m=2 -> [1,2), [3,3) -> 2 is correctly excluded
     */
    TreeNode* arrayRangeToBST(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nullptr;
        }

        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = arrayRangeToBST(nums, l, m); 
        root->right = arrayRangeToBST(nums, m+1, r); 
        return root;
    }
};
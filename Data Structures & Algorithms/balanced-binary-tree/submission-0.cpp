/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0; // Height of nothing is 0

        // 1. Get height of left side
        int lh = checkHeight(root->left);
        if (lh == -1) return -1; // If left is already broken, pass the error up

        // 2. Get height of right side
        int rh = checkHeight(root->right);
        if (rh == -1) return -1; // If right is already broken, pass the error up

        // 3. Check the balance AT THIS NODE
        if (abs(lh - rh) > 1) return -1; // Current node is broken!

        // 4. If everything is fine, return the actual height
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        // If the result is -1, it failed the balance test
        return checkHeight(root) != -1;
    }
};


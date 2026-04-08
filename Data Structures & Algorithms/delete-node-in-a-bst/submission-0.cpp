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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return nullptr;
        }

        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            // CASE(1) : Delete Leaf Nodes.
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            
            // CASE(2): Only One child is alive of the parent to be Deleted.
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // CASE(3): Both child alive.
            if(root->left && root->right){
                TreeNode* successor = root->right;
                while(successor->left){
                    successor = successor->left;
                }

                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* snd = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root, TreeNode* &last) {
        if (!root)
            return;

        inorder(root->left, last);

        if (last && last->val > root->val) {
            if (!first) {
                first = last;
                snd = root;
            } else
                snd = root;
        }

        last = root;

        inorder(root->right, last);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* last = new TreeNode(INT_MIN);
        inorder(root, last);
        
            swap(first->val, snd->val);
        
    }
};
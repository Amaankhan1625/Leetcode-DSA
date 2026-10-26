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
    int countNodes(TreeNode* root) {
          if (root == nullptr)
            return 0;

        int leftHeight = 0, rightHeight = 0;
        TreeNode* l = root;
        TreeNode* r = root;

        while (l) {
            leftHeight++;
            l = l->left;
        }

        while (r) {
            rightHeight++;
            r = r->right;
        }

        // Perfect binary tree
        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};
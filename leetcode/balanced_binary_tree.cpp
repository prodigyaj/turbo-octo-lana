/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int findDiff(TreeNode *root)
    {
        if(root == NULL)return 0;
        return 1+max(findDiff(root->left),findDiff(root->right));
    }
    bool isBalanced(TreeNode *root) {
        if(root == NULL)return true;
        int val = abs(findDiff(root->left)-findDiff(root->right));
        if(val < 2 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }
};

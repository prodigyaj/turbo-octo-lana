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
    
    bool getValid(TreeNode* root, long int minimum,long int maximum)
    {
        if(root == NULL)
            return true;
        if(!((root->val > minimum) && (root->val < maximum))) 
            return false;
        return getValid(root->left,minimum,root->val) && getValid(root->right,root->val,maximum);
    }
    
    bool isValidBST(TreeNode *root) {
        return getValid(root,LONG_MIN,LONG_MAX);
    }
};

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
    bool getSym(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL)return true;
        if(p==NULL || q==NULL)return false;
        if(p->val!=q->val)return false;
        
        return getSym(p->left,q->right) && getSym(p->right,q->left);
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)return true;
        return getSym(root->left,root->right);
    }
};

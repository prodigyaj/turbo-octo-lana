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
    vector <TreeNode *> v;
    
    void preOrder(TreeNode *root)
    {
        if(root!=NULL)
        {
            v.push_back(root);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void flatten(TreeNode *root) {
        
        if(root != NULL)
        {
            preOrder(root);
            for(int i=0;i<v.size();i++)
            {
                if(i==0)
                    root = v[0];
                else
                    {
                        root->right = v[i];
                        root->left = NULL;
                        root = root->right;
                    }
            }
        }
    }
};

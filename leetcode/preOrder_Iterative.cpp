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
    vector<int> preorderTraversal(TreeNode *root) {
        
        stack <TreeNode*> st;
        
        
        vector <int> v;
        if(root == NULL)return v;
        st.push(root);
        while(st.empty()!=true)
        {
            TreeNode* cur = st.top();st.pop();
            while(cur!=NULL)
            {
                if(cur->right!=NULL) //Keep Inserting the right nodes into the stack as these are required later
                    st.push(cur->right);
                v.push_back(cur->val);
                cur = cur->left;
            }
        }
        
        return v;
    }
};

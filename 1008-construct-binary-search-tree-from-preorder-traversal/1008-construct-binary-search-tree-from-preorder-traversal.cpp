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
     TreeNode* solve(vector<int>& pre,int &i,int min,int max,int n){
    if(i >= n or pre[i] >= max or pre[i]<=min) return NULL;
    
    TreeNode* root = new TreeNode(pre[i++]);
    
    root->left = solve(pre,i,min,root->val,n);
    root->right = solve(pre,i,root->val,max,n);
    
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i=0;
    return solve(preorder,i,INT_MIN,INT_MAX,preorder.size());
    }
};
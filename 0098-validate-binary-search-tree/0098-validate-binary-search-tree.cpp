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
    bool solve(TreeNode* root,TreeNode* mn,TreeNode* mx){
        if(root==NULL) return true;
        
       if(mn != NULL and root->val <= mn->val ){
           return false;
       }
        if(mx != NULL and root->val >= mx->val){
           return false;
       }
        bool left = solve(root->left,mn,root);
        bool right = solve(root->right,root,mx);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* mn=NULL;
        TreeNode* mx=NULL;
        return solve(root,mn,mx);
    }
};
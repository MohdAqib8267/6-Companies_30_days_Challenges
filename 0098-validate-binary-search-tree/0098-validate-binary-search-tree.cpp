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
         if(root==NULL){
            return true;
        }
        if(mx != NULL && root->val >= mx->val){
            return false;
        }
        if(mn != NULL && root->val <= mn->val){
            return false;
        }
        bool left=solve(root->left,mn,root);
        bool right=solve(root->right,root,mx);
        if(left && right){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* mn=NULL;
        TreeNode* mx=NULL;
      
        return solve(root, mn, mx);
        
    }
};
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
    bool solve(TreeNode* root,TreeNode* subRoot){
        if(root==NULL and subRoot != NULL){
            return false;
        }
        if(root!=NULL and subRoot==NULL){
            return false;
        }
         if(root==NULL and subRoot==NULL){
            return true;
        }
        if(root->val!=subRoot->val){
            return false;
        }
        bool left=solve(root->left, subRoot->left);
        bool right=solve(root->right,subRoot->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        if(root->val == subRoot->val){
            if(solve(root,subRoot)){
                return true;
            }
        }
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);
        return left || right;
    }
};
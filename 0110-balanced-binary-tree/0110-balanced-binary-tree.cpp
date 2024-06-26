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
    int solve(TreeNode* root,bool &flag){
        if(root==NULL){
            return 0;
        }
        int leftH=solve(root->left,flag);
      int rightH=solve(root->right,flag);
        if(abs(leftH-rightH)>1){
            flag=false;
        }
        return 1+max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool flag=true;
        int ans=solve(root,flag);
        return flag;
    }
};
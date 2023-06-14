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
    void solve(TreeNode* root,int &ans,TreeNode* &prev){
        if(root->left){
            solve(root->left,ans,prev);
        }
        if(prev!=NULL){
            ans=min(ans,abs(root->val - prev->val));
        }
            prev=root;
        if(root->right){
            solve(root->right,ans,prev);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        TreeNode* prev=NULL;
        solve(root,ans,prev);
        return ans;
    }
};
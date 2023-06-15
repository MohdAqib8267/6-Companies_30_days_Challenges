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
    void solve(TreeNode* root,int &ans,int mx){
        if(root==NULL) return;
        if(root->val>=mx){
            //root ki value current path ki max value se zyada hai, mtlb koi node nhi hai kmm  ki
            ans++;
            mx=max(mx,root->val);
        }
        solve(root->left,ans,mx);
        solve(root->right,ans,mx);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        int mx=INT_MIN;
         solve(root,ans,mx);
        return ans;
    }
};
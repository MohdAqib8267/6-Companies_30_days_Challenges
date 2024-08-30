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
    vector<int>ans;
    void solve(TreeNode* root,int total){
          if(root==NULL){
            return;
        }
        if(root->left ==NULL && root->right == NULL){
            total=10*total+root->val;
            ans.push_back(total);
            return;
        }
      
        total=10*total+root->val;
        solve(root->left,total);
        solve(root->right,total);
        
    }
    int sumNumbers(TreeNode* root) {
        int total=0;
         solve(root,total);
        return accumulate(ans.begin(),ans.end(),0);
    }
};
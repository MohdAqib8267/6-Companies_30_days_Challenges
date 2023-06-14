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
      void dfs(TreeNode* root,string temp,vector<string>& ans){
        if(root==NULL){
            
            return;
        }
        temp=temp+to_string(root->val)+"->";
        if(root->left==NULL and root->right==NULL){
        
            temp.pop_back();
             temp.pop_back();
            ans.push_back(temp);
            return;
        }
        if(root->left!=NULL){
           
            dfs(root->left,temp,ans);
        }
        if(root->right!=NULL){
         
            dfs(root->right,temp,ans);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        dfs(root,temp,ans);
        return ans;
    }
};
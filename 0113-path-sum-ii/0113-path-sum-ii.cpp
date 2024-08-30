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
  void getpath(TreeNode* root,vector<vector<int>>& ans,vector<int> paths,int sum,int target){
        if(root==NULL)
            return;
        sum=sum+root->val;
        paths.push_back(root->val);
        if(sum==target and root->left==NULL and root->right==NULL){
            ans.push_back(paths);
        }
        getpath(root->left,ans,paths,sum,target);
        getpath(root->right,ans,paths,sum,target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>paths;
        getpath(root,ans,paths,0,targetSum);
        return ans;
    }
};
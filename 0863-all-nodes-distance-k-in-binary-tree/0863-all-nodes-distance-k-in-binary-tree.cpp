/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void convert(TreeNode* root,vector<int>adj[]){
        if(root==NULL) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        convert(root->left,adj);
        convert(root->right,adj);
    }
    void dfs(int target,int k,vector<int>adj[],vector<int>&ans,vector<bool>&vis){
        vis[target]=true;
        if(k==0){
            ans.push_back(target);
            return;
        }
        for(auto it:adj[target]){
            if(!vis[it]){
                dfs(it,k-1,adj,ans,vis);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //method 1 (convert Tree into graph
        vector<int>adj[501];
        convert(root,adj);
        //now dfs on adj
        vector<int>ans;
        vector<bool>vis(501,false);
        dfs(target->val,k,adj,ans,vis);
        return ans;
    }
};
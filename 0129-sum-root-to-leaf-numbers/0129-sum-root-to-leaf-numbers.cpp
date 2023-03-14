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
    void DFS(TreeNode* root,vector<int>& ans,int sum){
        if(root==NULL){
            
            return;
        }
        sum=sum*10+root->val;
        if(root->left==NULL and root->right==NULL){
            ans.push_back(sum);
        }
        DFS(root->left,ans,sum);
        DFS(root->right,ans,sum);
    }
    int sumNumbers(TreeNode* root) {
        vector<int>ans;
        DFS(root,ans,0);
        int res=0;
        for(int i=0;i<ans.size();i++){
            res=res+ans[i];
        }
        return res;
        
    }
};
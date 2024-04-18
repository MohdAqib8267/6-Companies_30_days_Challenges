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
    void solve(TreeNode* root,vector<int>temp,vector<vector<int>>&paths){
        if(root!= NULL && root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            paths.push_back(temp);
            return;
        }
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        solve(root->left,temp,paths);
        solve(root->right,temp,paths);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        vector<vector<int>>paths;
        vector<int>temp;
        solve(root,temp,paths);
        for(auto it:paths){
            vector<int>path=it;
            string str="";
            for(int i=0;i<path.size();i++){
                if(i != path.size()-1){
                    str=str+to_string(path[i])+"->";
                }else{
                    str=str+to_string(path[i]);
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};
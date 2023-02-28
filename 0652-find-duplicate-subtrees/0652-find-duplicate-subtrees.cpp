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
    string solve(TreeNode* root,unordered_map<string,int>&mp,vector<TreeNode*>&ans){
        if(root==NULL){
            return "";
        }
        string left = solve(root->left,mp,ans);
        string right = solve(root->right,mp,ans);
        string curr = to_string(root->val)+" "+left+" "+right;
        if(mp[curr]==1){
            ans.push_back(root);
        }
        
            mp[curr]++;
        
        return curr;
    }
        
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<TreeNode*>ans;
        string dummy = solve(root,mp,ans);
        return ans;
    }
};
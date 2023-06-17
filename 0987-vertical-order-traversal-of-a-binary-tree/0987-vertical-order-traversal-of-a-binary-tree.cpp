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
    map<int,vector<pair<int,int>>>mp;
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.second<b.second){
            return true;
        }
        else if(a.second==b.second){
            return a.first<b.first;
        }
        return false;
    } 
    void solve(TreeNode* root,int r,int c){
        if(root==NULL) return;
        solve(root->left,r+1,c-1);
        mp[c].push_back({root->val,r});
        solve(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        solve(root,0,0);
        vector<vector<int>>ans;
        
        for(auto it:mp){
            vector<pair<int,int>>temp=it.second;
            sort(temp.begin(),temp.end(),cmp);
            vector<int>v;
            for(int i=0;i<temp.size();i++){
                 v.push_back(temp[i].first);
            }
           ans.push_back(v);
        }
        return ans;
    }
};
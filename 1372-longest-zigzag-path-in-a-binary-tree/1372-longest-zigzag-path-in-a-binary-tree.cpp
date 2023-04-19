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
    int maxi=INT_MIN;
    void solve(TreeNode* root,string dir,int cnt){
        if(root==NULL){
            return;
        }
        maxi=max(maxi,cnt);
        if(dir=="left"){
            solve(root->right,"right",cnt+1);
            solve(root->left,"left",1);
        }
        else{
            solve(root->left,"left",cnt+1);
            solve(root->right,"right",1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root,"left",0);
        solve(root,"right",0);
        return maxi==INT_MIN? 0 : maxi;
    }
};
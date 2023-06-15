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
    void checkForNode(TreeNode* root,long long sum,int target,int &cnt){
        if(root==NULL) return;
        sum+=root->val;
        if(sum==target) cnt++;
        
         checkForNode(root->left,sum,target,cnt);
         checkForNode(root->right,sum,target,cnt);
    }
    void solve(TreeNode* root,int &cnt, int targetSum){
        if(root==NULL) return;
        
        checkForNode(root,0,targetSum,cnt);
        solve(root->left,cnt,targetSum);
        solve(root->right,cnt,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        if(root==NULL) return 0;
        solve(root,cnt,targetSum);
        return cnt;
    }
};
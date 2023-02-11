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
    void findPath(TreeNode* root,int &cnt,long long sum,int targetSum){
        if(root==NULL){
            return;
        }
        sum=sum+root->val;
        if(sum==targetSum){
            cnt++;
        }
        findPath(root->left,cnt,sum,targetSum);
        findPath(root->right,cnt,sum,targetSum);
    }
    void solve(TreeNode* root,int &cnt,int targetSum){
        if(root==NULL){
            return;
        }
        findPath(root,cnt,0,targetSum);
        solve(root->left,cnt,targetSum);
        solve(root->right,cnt,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        solve(root,cnt,targetSum);
        return cnt;
    }
};
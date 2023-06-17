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
    int solve(TreeNode* root,int &maxSum){
        if(root==NULL) return 0;
        int left = max(0,solve(root->left,maxSum));
        int right = max(0,solve(root->right,maxSum));
        maxSum = max(maxSum,left+right+root->val); // path sum including child
         return root->val+max(left,right); //return maximum left and right subtrees including current root
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        solve(root,sum);
        return sum;
    }
};
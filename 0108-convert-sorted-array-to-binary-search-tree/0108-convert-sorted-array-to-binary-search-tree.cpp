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
    TreeNode* solve(int i,int j,vector<int>&nums){
        if(i<=j){
            int mid=(i+j)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=solve(i,mid-1,nums);
            root->right=solve(mid+1,j,nums);
                    return root;
        }else
        return NULL;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};
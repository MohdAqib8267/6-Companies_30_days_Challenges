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
    int solve(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        //postorder
        int lh=solve(root->left,ans);
        int rh=solve(root->right,ans);
        ans=max(ans,1+lh+rh);
        return 1+max(lh,rh);
    }
    
    int calcDiameter(TreeNode* root,int *height){
        if(root==NULL) return 0;
        
        int lh=0, rh=0;
        int leftDia = calcDiameter(root->left,&lh);
        int rightDia = calcDiameter(root->right,& rh);
        *height = 1+max(lh,rh);
        int currDia = 1+lh+rh;
        return max({currDia,leftDia,rightDia});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //Methid 1
        // int ans=INT_MIN;
        // solve(root,ans);
        // return ans-1;
        
        //Method 2
        int height=0;
        return calcDiameter(root,&height)-1;

    }
};
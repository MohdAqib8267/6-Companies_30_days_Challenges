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
    //good
//        int height(TreeNode* root,int& ans){
//         if(root==NULL){
//             return 0;
//         }
//         int lh = height(root->left,ans);
//         int rh = height(root->right,ans);
        
//         ans = max(ans,1+lh+rh);
//         return 1+max(lh,rh);
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         int ans = INT_MIN;
//         height(root,ans);
//         return ans-1;
//     }
    
    
    int calcDiameter(TreeNode* root,int *height){
        if(root==NULL){
            return 0;
        }
        int lh=0;
        int rh=0;
        int left_dia=calcDiameter(root->left,&lh);
        int right_dia=calcDiameter(root->right,&rh);
        int currDiameter=(lh+rh+1);
        *height=max(lh,rh)+1;
        return max({currDiameter,left_dia,right_dia});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height=0;
        
        return calcDiameter(root,&height)-1;
    }
};
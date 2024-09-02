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
    vector<int>inorder;
    void inorderTraversal(TreeNode* root){
        if(root==NULL) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    TreeNode* SortedArrayToBST(int st,int en){
        if(st>en) return NULL;
        if(st==en) return new TreeNode(inorder[st]);
        int mid = (st+en)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = SortedArrayToBST(st,mid-1);
        root->right = SortedArrayToBST(mid+1,en);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return SortedArrayToBST(0,inorder.size()-1);
    }
};
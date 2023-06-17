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
    TreeNode* solve(int &idx,int st,int en,vector<int>& inorder, vector<int>& postorder){
        if(st>en) return NULL;
        int curr=postorder[idx];
        idx--;
        TreeNode* root=new TreeNode(curr);
        int pos;
        for(int i=st;i<=en;i++){
            if(inorder[i]==curr){
                pos=i;
                break;
            }
        }
        root->right=solve(idx,pos+1,en,inorder,postorder);
        root->left=solve(idx,st,pos-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return solve(idx,0,inorder.size()-1,inorder,postorder);
    }
};
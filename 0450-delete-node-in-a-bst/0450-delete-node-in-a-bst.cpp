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
    TreeNode* inorderSucc(TreeNode* root){
        TreeNode* curr=root;
        while(curr!=NULL and curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            //case 1 & 2
            if(root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* temp=inorderSucc(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};
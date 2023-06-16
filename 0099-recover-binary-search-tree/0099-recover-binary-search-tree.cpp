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
    TreeNode* first, *last, *middle, *prev;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev && (prev->val > root->val)){
            if(first == NULL){
                //first time gadbad hue
                first=prev;
                middle=root;
            }
            else{
                //second time gadbad
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=middle=NULL;
         prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            swap(first->val,last->val);
        }
        else if(first and middle){
            swap(first->val,middle->val);
        }
        return;
    }
    
};
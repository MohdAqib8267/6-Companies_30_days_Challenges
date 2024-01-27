/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
      void preorder(string &s,TreeNode* r){
        if(r){
            s+=to_string(r->val)+" ";
            preorder(s,r->left);
            preorder(s,r->right);
        }
    }
    
   void buildpreorder(int s,TreeNode* r){
        if(r!=NULL){
            if(s > r->val && r->right){
                buildpreorder(s,r->right);
            }else{
                if(s < r->val && r->left){
                    buildpreorder(s,r->left);
                }
                else{
                    if(s > r->val){
                        TreeNode* p=new TreeNode(s);
                        r->right=p;
                    }else{
                        TreeNode* p=new TreeNode(s);
                        r->left=p;
                    }
                }
            }
        }
    }
    
    string serialize(TreeNode* root) {
         string res="";
        preorder(res,root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> des;
        string k="";
        for(char c:data){
          if(c!=' '){
            k+=c;
          }
          else{
              des.push_back(stoi(k));
              k="";

        }}int i=0;
          if(des.size()){
                    TreeNode *head=new TreeNode(des[0]);
                  for(int i=1;i<des.size();i++){
                      buildpreorder(des[i],head);
                  }
              return head;

          }
              return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
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
     void preorder(TreeNode* root,string &data){
         if (root == nullptr) {
        data += "X,";
        return;
    }

    data += to_string(root->val) + ",";
    preorder(root->left, data);
    preorder(root->right, data);
    }
    
    
    TreeNode* deserializeHelper(queue<string>& q) {
    if (q.empty()) return nullptr;

    string s = q.front();
    q.pop();

    if (s == "X") {
        return nullptr;
    }

    int value = stoi(s);
    TreeNode* root = new TreeNode(value);

    root->left = deserializeHelper(q);
    root->right = deserializeHelper(q);

    return root;
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root,s);
        s.pop_back();
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
  
    TreeNode* deserialize(string data) {
     
        queue<string> q;
        string val;

        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') continue;
            string nodeVal;
            
            while (i < data.size() && data[i] != ',') {
                nodeVal += data[i];
                i++;
            }
            q.push(nodeVal);
        }

        TreeNode* root = deserializeHelper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
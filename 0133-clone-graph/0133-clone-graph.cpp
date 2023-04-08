/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(Node* node,Node* copy,vector<Node*>& vis){
      
        vis[copy->val]=copy;
        for(auto x:node->neighbors){
            if(vis[x->val]==NULL){
                Node* newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode);
                solve(x,newNode,vis);
            }
            else{
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
        
    }
    Node* cloneGraph(Node* node) {
        vector<Node*>vis(101,NULL);
        if(node==NULL){
            return NULL;
        }
        Node* copy = new Node(node->val);
        solve(node,copy,vis); 
        return copy;
        
    }
};
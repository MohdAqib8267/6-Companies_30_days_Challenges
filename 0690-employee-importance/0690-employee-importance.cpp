/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void DFS(int id, unordered_map<int,Employee*>&mp,int &sum){
        sum=sum+mp[id]->importance;
        for(auto it:mp[id]->subordinates){
            DFS(it,mp,sum);
        }
        return;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        for(auto x:employees){
            mp[x->id]=x;
        }
        int sum=0;
        DFS(id,mp,sum);
        return sum;
    }
};
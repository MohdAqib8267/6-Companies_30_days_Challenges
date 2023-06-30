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
    void DFS(int id,unordered_map<int,Employee*>& mp,int &sum){
        sum=sum+mp[id]->importance;
        for(auto x:mp[id]->subordinates){
            DFS(x,mp,sum);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        unordered_map<int,Employee*>mp;
        for(auto it:employees){
            mp[it->id]=it;
        }
        int sum=0;
        DFS(id,mp,sum);
        return sum;
    }
};
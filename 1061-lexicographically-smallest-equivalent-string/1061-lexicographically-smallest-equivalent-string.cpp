class Solution {
public:
     int parent[26]; 
    // Find function to find the representative element of the set containing the character
    int find(int ch){
        return ch == parent[ch] ? ch : parent[ch] = find(parent[ch]);
    }
    // Union function to merge the set containing x and the set containing y
    void union_set(int x, int y){
        x = find(x);
        y = find(y);
        if(x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans;
        // Initialize all elements of temp array to its index
        for(int i=0;i<26;i++) parent[i] = i;
        // Iterate through s1 and s2 and union the sets containing the corresponding characters
        for(int i=0;i<s1.size();i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            union_set(u,v);
        }
            
        // Iterate through baseStr and find the representative element of the set containing each character
        // and append it to the ans string
        for(char it : baseStr)
            ans += (char)(find(it - 'a') + 'a');
        return ans;
    }
};
class Solution {
public:
    int find(int a,int b){
        if(a<b){
            swap(a,b);
        }
        if(b==0) return a;
        return find(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return "";
        }
        int gcd = find(str1.size(),str2.size());
        return str1.substr(0,gcd);
    }
};
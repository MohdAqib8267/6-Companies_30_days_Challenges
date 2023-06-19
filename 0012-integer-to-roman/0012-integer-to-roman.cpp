class Solution {
public:
    string intToRoman(int num) {
        map<int,string,greater<int>>m;
        m[1000] = "M";
        m[900] = "CM";
        m[500] = "D";
        m[400] = "CD";
        m[100] = "C";
        m[90] = "XC";
        m[50] = "L";
        m[40] = "XL";
        m[10] = "X";
        m[9] = "IX";
        m[5] = "V";
        m[4] = "IV";
        m[1] = "I";
        string ans;
       
        for(auto it:m){
            while(num>=it.first){
                ans=ans+it.second;
                num=num-it.first;
            }
        }
        return ans;
    }
};
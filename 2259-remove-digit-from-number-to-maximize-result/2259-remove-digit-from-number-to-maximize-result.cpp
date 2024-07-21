class Solution {
public:
    string removeDigit(string number, char digit) {
        string mx="";
        
        for(int i=0;i<number.size();i++){
            if(number[i] == digit){
                string str = number.substr(0,i)+number.substr(i+1);
                mx=max(mx,str);
            }
        }
        return mx;
    }
};
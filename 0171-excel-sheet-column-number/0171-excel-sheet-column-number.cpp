class Solution {
public:
//     1. There are 26 letters in our alphabet and we start counting from 1, not zero.
//    So 'Z' is 26.
// 2. The rest of the combinations start from a base 26

// AA --> 26*1+ 1 = 27 (A == 1)
// AB --> 26*1+ 2 = 28 (B == 2)
// AC -->26*1 + 3 = 29 (C == 3)
// .....

// So we can write like this:

// result = 0
// d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a number like it's going to be C)
// result = result* 26 + d

// If the given input is only one letter, it will automatically take the value s[i] - 'A' + 1 as the first result is 0.
    
    
    int titleToNumber(string columnTitle) {
      int res=0;
        for(int i=0;i<columnTitle.size();i++){
            int d=(columnTitle[i]-'A'+1);
            res=26*res+d;
        }
        return res;
    }
};
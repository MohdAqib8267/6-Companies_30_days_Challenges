class Solution {
public:
    int compress(vector<char>& chars) {
       int i=0;
        int ansIndex =0;
        while(i<chars.size())
        {
            int j=i+1;
            while(j<chars.size() && chars[i]==chars[j])
            {
                j++;
            }
           // hum yaaha per ansIndex++ islye kar re kyu ki har value k sath yeah apane aap badheeeee
            chars[ansIndex++]=chars[i];

            int count = j-i;

            if(count>1)
            { 
                
                
                 //yeah islye kya kyu ki hame 1 2 alag hona agar 12 answer aaay toh 


                string cnt= to_string(count);
                for(char ch: cnt)
                {
                    chars[ansIndex++]=ch;
                }
            }

            //agar hum soche toh jo j ki location hogi vhoi h next char ki location hogee 
            i=j;
        }
             //hume bola gaay tha ki humee size return karni hai aur ...int function diya hua hai
        return ansIndex;
    }
};
class Solution {
public:
    string removeOccurrences(string s, string part) {
         int p=part.size();

            int i=0;
            while(i<s.length())
            {
                if(s[i]==part[0])
                {
                    string st=s.substr(i,p);
                    if(st==part)
                    {
                        s=s.substr(0,i)+s.substr(i+p);
                        i=-1;
                    }
                }
                i++;
            }
            return s;
    }
};
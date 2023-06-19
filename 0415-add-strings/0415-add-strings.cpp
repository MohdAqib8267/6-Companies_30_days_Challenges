class Solution {
public:
      string addStrings(string a, string b) {
      int n=a.size();
    int m=b.size();
    int carry=0;
    
    vector<int>tmp;
    string s;
    
    int i,j;
    
    for(i=n-1,j=m-1;i>=0 && j>=0;i--,j--)
    {
        int t=(a[i]-'0')+(b[j]-'0')+carry;
        carry=0;
        //cout<<"t  "<<t<<"  ";
        if(t>=10)
        {
            carry=t/10;
            tmp.push_back(t%10);
        }
        else
            tmp.push_back(t);
        
        //cout<<"c  "<<c<<"   ";
    }
    //cout<<"c  "<<carry;
    while(i>=0)
    {
        int t=carry+(a[i]-'0');
        if(t>=10)
        {
            int carry=t/10;
            tmp.push_back(t%10);
        }
        else
        {
            carry=0;
            tmp.push_back(t);
        }    
        i--;
    }
    while(j>=0)
    {
        int t=carry+(b[j]-'0');
        if(t>=10)
        {
            int carry=t/10;
            tmp.push_back(t%10);
        }
        else
        {
            carry=0;
            tmp.push_back(t);
        }   
        j--;
    }
    if(carry)
    {
        tmp.push_back(carry);
    }
    
    for(int i=tmp.size()-1;i>=0;i--)
    {
        
        s.push_back(tmp[i]+'0');
    }
    return s;
    }
};
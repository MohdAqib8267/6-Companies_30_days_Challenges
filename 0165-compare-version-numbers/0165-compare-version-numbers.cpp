class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        vector<int>s1,s2;
        string temp="";
        int num=0;
        for(int i=0;i<n1;i++){
            if(version1[i]!='.'){
                num=num*10+(version1[i]-'0');
            }
            else{
                
                   s1.push_back(num); 
                
                num=0;
            }
        }
        s1.push_back(num);
        int num2=0;
         for(int i=0;i<n2;i++){
            if(version2[i]!='.'){
                num2=num2*10+(version2[i]-'0');
            }
            else{
               
                   s2.push_back(num2); 
                
                num2=0;
            }
        }
         s2.push_back(num2);
        for(int i=0;i<s1.size();i++){
            cout<<s1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<s2.size();i++){
            cout<<s2[i]<<" ";
        }
        int i=0,j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]<s2[j]){
                return -1;
            }
            else if(s1[i]>s2[j]){
                return 1;
            }
            i++;j++;
        }
        
        if(i<s1.size()){
            while(i<s1.size()){
               if(s1[i]>0){
                return 1;
                } 
                 i++;
            }
           
        }
        if(j<s2.size()){
            while(j<s2.size()){
               if(s2[j]>0){
                return -1;
                } 
                  j++;
            }
          
        }
      
            return 0;
        
      
    }
};
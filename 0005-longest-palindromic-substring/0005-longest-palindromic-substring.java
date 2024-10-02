class Solution {
    public String longestPalindrome(String s) {
        int n=s.length();
        int st=-1;
        int size=0;
        if(n==1) return s;
        for(int i=0;i<n;i++){
            int lo=i-1;
            int hi=i+1;
            while(lo>=0 && s.charAt(lo)==s.charAt(i)){
                lo--;
            }
            while(hi<n && s.charAt(hi)==s.charAt(i)){
                hi++;
            }
            while(lo>=0 && hi<n && s.charAt(lo)==s.charAt(hi)){
                lo--;
                hi++;
            }
            if(hi-lo-1 > size){
                st=lo+1;
                size=hi-lo-1;
            }
        }
        // System.out.println(st+" "+size);
        return s.substring(st,st+size); //starting index,ending index(exclusive)
    }
}
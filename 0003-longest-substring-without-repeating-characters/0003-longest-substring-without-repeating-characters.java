class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>mp = new HashMap<Character,Integer>();
        int j=0;
        int i=0;
        int ans=0;
        int n=s.length();
        while(j<n){
            if(mp.getOrDefault(s.charAt(j),0)>0){
               while(mp.getOrDefault(s.charAt(j),0)>0){
                   mp.put(s.charAt(i),mp.getOrDefault(s.charAt(i),0)-1);
                   i++;
               } 
            }
            mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)+1);
            ans=Math.max(ans,j-i+1);
            j++;
        }
        return ans;
    }
}
class Solution {
    public int numUniqueEmails(String[] emails) {
        int n=emails.length;
        int count=0;
        Map<String,Integer>mp = new HashMap<>();
        for(String s:emails){
            StringBuilder sb = new StringBuilder("");
            Boolean find = false;
            for(int i=0;i<s.length();i++){
                char ch = s.charAt(i);
                if(ch == '@'){
                    sb.append(s.substring(i)); 
                    break;
                }
                if(find) continue;
                
                if (ch == '+') {
                    find = true; 
                    continue;
                }
                if(ch!='.'){
                   sb.append(ch);
                }
                
            }
            String cleanEmail = sb.toString();
            mp.put(cleanEmail, mp.getOrDefault(cleanEmail, 0) + 1);
        }
        return mp.size();
    }
}
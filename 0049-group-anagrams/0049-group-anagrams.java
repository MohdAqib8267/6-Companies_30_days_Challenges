class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>>ans=new ArrayList<>();
        Map<String,List<String>>mp=new HashMap<>();
        for(int i=0;i<strs.length;i++){
            String str=strs[i];
            char[] strArr = str.toCharArray();
            Arrays.sort(strArr);
            String sortedString = new String(strArr);
            if(!mp.containsKey(sortedString)){
                // if map does not contain key, then add key with a new list
                mp.put(sortedString,new ArrayList<>());
            }
            mp.get(sortedString).add(str);
            
        }
        for(Map.Entry<String,List<String>>entry:mp.entrySet()){
            // System.out.println(entry.getValue());
            ans.add(new ArrayList<>(entry.getValue()));
        }
        return ans;
    }
}
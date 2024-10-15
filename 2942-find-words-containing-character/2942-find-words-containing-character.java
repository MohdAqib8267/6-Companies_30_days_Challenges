class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer>list = new ArrayList<>();
        // String ch_string = x+"";
        // or
        String ch_string = Character.toString(x); 
        for(int i=0;i<words.length;i++){
            String s=words[i];
            
            if(s.contains(ch_string)){
                list.add(i);
            }
        }
        return list;
    }
}
class Solution {
    public boolean solve(int i, String s, Set<String> st, List<Integer> dp) {
        
        // Base case: If we've reached the end of the string
        if (i >= s.length()) return true;
        
        // If the result for this index is already computed, return it
        if (dp.get(i) != -1) return dp.get(i) == 1; // Return true if 1, false if 0
        
        String sub = "";
        for (int j = i; j < s.length(); j++) {
            sub += s.charAt(j);
            if (st.contains(sub)) {
                System.out.println(sub); // Debugging output to show matching substrings
                
                // If the remaining part of the string can be segmented, mark dp[i] as true (1)
                if (solve(j + 1, s, st, dp)) {
                    dp.set(i, 1); // Mark dp[i] as 1 (true)
                    return true;
                }
            }
        }
        
        // If no valid segmentation is found, mark dp[i] as false (0)
        dp.set(i, 0);
        return false;
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> st = new HashSet<>(wordDict); // Initialize set directly from the wordDict
        List<Integer> dp = new ArrayList<>(Collections.nCopies(s.length(), -1)); // Initialize DP with -1
        return solve(0, s, st, dp); // Call the recursive solve function
    }
}
class Solution {
    public int minExtraChar(String s, String[] dictionary) {
       Set<String> st = new HashSet<>(Arrays.asList(dictionary)); // Convert dictionary to a set for O(1) lookups
        int n = s.length();

        // DP array where dp[i] represents the minimum number of extra characters for s[0...i-1]
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n); // Initialize with max value (i.e., the worst case: all characters are extra)
        dp[0] = 0; // Base case: no characters, no extra characters

        for (int i = 1; i <= n; i++) {
            // Check all possible substrings ending at position i-1
            for (int j = 0; j < i; j++) {
                String sub = s.substring(j, i);
                // If the substring is in the dictionary, update dp[i]
                if (st.contains(sub)) {
                    dp[i] = Math.min(dp[i], dp[j]);
                }
            }
            // Also consider the case where the current character s[i-1] is an extra character
            dp[i] = Math.min(dp[i], dp[i - 1] + 1);
        }

        return dp[n];
    }
}
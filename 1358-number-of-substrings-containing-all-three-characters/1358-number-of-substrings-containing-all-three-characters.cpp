class Solution {
public:
    int numberOfSubstrings(string s) {
        //brute force
        //create a map and iterate through the string using 2 nested loop
        //when freq of a,b and c in map greater than or equal to 1 then 
        //increment count++; time complexity is O(N2)
        
//           int result = 0;

//     // Iterate over all substrings of s
//     for (int i = 0; i < s.size(); i++) {
//         // Initialize counters for each character
//         unordered_map<char, int> counts;

//         // Iterate over the characters of the current substring
//         for (int j = i; j < s.size(); j++) {
//             counts[s[j]]++;

//             // If all characters have been seen at least once, increment the result
//             if (counts['a'] > 0 && counts['b'] > 0 && counts['c'] > 0) {
//                 result++;
//             }
//         }
//     }

//     return result;
        
        //Optimise solution--->(sliding window) optimisation of brute force
//         We initialize a map counts that will keep track of the counts of each character a, b, and c.
// We also initialize two variables left and right that will mark the ends of the sliding window.
// We then enter a loop that will slide the window over the string. At each iteration, we update the count of the character at the right end of the window and check if all three characters have been seen at least once. If they have, we increment the result by the number of substrings that can be formed with the current window (i.e., s.size() - right).
// If the window size exceeds 3, we update the count of the character at the left end of the window and move the left end of the window.
// Finally, we move the right end of the window.
// This algorithm has a time complexity of O(n), where n is the length of the string.
        
        //jese hi hmey ek string mileygi to uski jth loop wale bhi sab string dennge unhe dirctly count krey
        unordered_map<char,int>count;
        int left=0,right=0;
        int result=0;
        int n=s.size();
        while(right<n){
            count[s[right]]++;
            while(count['a']>0 and count['b']>0 and count['c']>0){
                    result=result+(n-right);
                    count[s[left]]--;
                    left++; 

            }
            right++;
        }
        return result;
    }
};
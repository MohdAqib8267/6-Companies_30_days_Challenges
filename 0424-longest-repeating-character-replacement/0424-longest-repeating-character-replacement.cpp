class Solution {
public:
    int characterReplacement(string str, int k) {
        int windowStart = 0,windowEnd=0, maxLength = 0, maxRepeatLetterCount = 0;
    unordered_map<char, int> letterFrequencyMap;
    
    while( windowEnd < str.length()) {
      char rightChar = str[windowEnd];
      letterFrequencyMap[rightChar]++;
      maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[rightChar]);
      if ((windowEnd - windowStart + 1 - maxRepeatLetterCount) > k) {
        char leftChar = str[windowStart];
        letterFrequencyMap[leftChar]--;
        windowStart++;
      }

      maxLength = max(maxLength, windowEnd - windowStart + 1);
        windowEnd++;
    }

    return maxLength;
    }
};
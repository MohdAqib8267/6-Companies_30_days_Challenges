class Solution {
public List<String> splitWordsBySeparator(List<String> words, char separator) {
    List<String> list = new ArrayList<>();  // Result list
    String regexSeparator = "\\" + separator;  // Escape the separator if it's a special regex character
    for (String s : words) {
        String[] arr = s.split(regexSeparator);  // Split the string using the escaped separator
        for (String newS : arr) {
            if (!newS.isEmpty()) {  // Optionally skip empty strings
                list.add(newS);  // Add each word to the result list
            }
        }
    }
    return list;
}
}
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        final Map<String, List<String>> groups = new HashMap<>();
        for (String s: strs) {
            final int[] charCount = new int[26];
            for (int i =0; i<s.length(); i++) {
                charCount[s.charAt(i) - 'a']++; 
            }
            String countToString = "";
            for (int i: charCount) countToString += i;
            groups.computeIfAbsent(countToString, k -> new ArrayList<>());
            groups.get(countToString).add(s);
        }
        final List<List<String>> result = new ArrayList<>();
        for(List<String> val: groups.values()) {
            result.add(val);
        }
        return result;
    }
}

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        final Map<String, List<String>> groups = new HashMap<>();
        for (String s: strs) {
            final int[] charCount = new int[26];
            for (int i =0; i<s.length(); i++) {
                charCount[s.charAt(i) - 'a']++; 
            }
            String countToString = "";
            for (int i: charCount) countToString += i + ",";
            groups.compute(countToString, (k, v) -> {
                if (v == null) v = new ArrayList<>();
                v.add(s);
                return v;
            });
        }
        return groups.values().stream().toList();
    }
}

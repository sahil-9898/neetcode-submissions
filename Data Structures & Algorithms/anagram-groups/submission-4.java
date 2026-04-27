class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        final Map<String, List<String>> groups = new HashMap<>();
        for (String s: strs) {
            final int[] charCount = new int[26];
            s.chars().forEach(c -> charCount[c - 'a']++);
            StringBuilder countToString = new StringBuilder();
            for (int i: charCount) countToString.append(i).append(",");
            groups.compute(countToString.toString(), (k, v) -> {
                if (v == null) v = new ArrayList<>();
                v.add(s);
                return v;
            });
        }
        return groups.values().stream().toList();
    }
}

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        final Map<Character, Integer> charCount = new HashMap<>();
        for (int i=0; i<s.length(); i++) {
            Character c = s.charAt(i);
            charCount.put(c, charCount.getOrDefault(c, 0) + 1);
        }
        for (int i=0; i<t.length(); i++) {
            Character c = t.charAt(i);
            charCount.put(c, charCount.getOrDefault(c, 0) - 1);
            if (charCount.get(c) < 0) return false;
        }
        return true;
    }
}

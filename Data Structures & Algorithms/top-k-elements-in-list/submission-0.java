class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        final Map<Integer, Integer> countMap = new HashMap<>();
        for (final int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        final List<Integer> result = new ArrayList<>();
        countMap.forEach((key, value) -> {
            if (value >= k) {
                result.add(key);
            }
        });
        return result.stream().mapToInt(i -> i).toArray();  
    }
}

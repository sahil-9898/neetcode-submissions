class Solution {
    public int[] twoSum(int[] nums, int target) {
        final Map<Integer, Integer> indexMap = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            final int difference = target - nums[i];
            if (indexMap.containsKey(difference)) {
                return new int[]{indexMap.get(difference), i};
            }
            indexMap.put(nums[i], i);
        }
        return new int[0];
    } 
}

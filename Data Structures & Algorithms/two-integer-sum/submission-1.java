class Solution {
    public int[] twoSum(int[] nums, int target) {
        final int[] result = new int[2];
        final Map<Integer, Integer> indexMap = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            final int difference = target - nums[i];
            if (indexMap.containsKey(difference)) {
                result[0] = indexMap.get(difference);
                result[1] = i;
                return result;
            }
            indexMap.put(nums[i], i);
        }
        return null;
    } 
}

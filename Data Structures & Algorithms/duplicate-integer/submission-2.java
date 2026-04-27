class Solution {
    public boolean hasDuplicate(int[] nums) {
        final Set<Integer> s = new HashSet<>();
        final int size = nums.length;
        for (int i=0; i<size; i++) {
            if(s.contains(nums[i])) return true;
            s.add(nums[i]);
        }
        return false;
    }
}

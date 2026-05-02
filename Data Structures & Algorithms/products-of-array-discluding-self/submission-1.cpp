class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);
        vector<int> res(size);

        // prepare prefix array
        int product = 1;
        for (int i=0; i<size; i++) {
            prefix[i] = product;
            product *= nums[i];
        }

        // prepare suffix array
        product = 1;
        for (int i=size-1; i>=0; i--) {
            suffix[i] = product;
            product *= nums[i];
        }

        // prepare res array
        for (int i=0; i<size; i++) {
            res[i] = prefix[i] * suffix[i];
        }
        return res;
    }
};

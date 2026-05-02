class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int size = nums.size();
        for (int i=0; i<size; i++) {
            int product = 1;
            for (int j=0; j<size; j++) {
                if (j!=i) {
                    product *= nums[j];
                }
            }
            res.push_back(product);
        }
        return res;
    }
};

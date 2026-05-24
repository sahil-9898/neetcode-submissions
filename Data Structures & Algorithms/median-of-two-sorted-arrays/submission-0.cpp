class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;

        int m = nums1.size();
        int n = nums2.size();

        int i=0,j=0;
        while (i<m || j<n) {
            if (i<m && j<n) {
                if (nums1[i] < nums2[j]) {
                    arr.push_back(nums1[i]);
                    i++;
                }
                else {
                    arr.push_back(nums2[j]);
                    j++;
                }
            }
            else if (i<m) {
                arr.push_back(nums1[i]);
                i++;
            }
            else if (j < n) {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        int s = arr.size();
        if (s%2!=0) {
            return arr[s/2];
        }
        return (arr[s/2] + arr[(s/2)-1]) / 2.0;
    }
};

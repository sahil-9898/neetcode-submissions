class Solution {
public:

    bool binary2d(int start, int end, int target, vector<vector<int>>& matrix) {
        if (start > end) return false;
        int mid = (start + end) / 2;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = mid / n;
        int j = mid % n;
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] > target) {
            return binary2d(start, mid - 1, target, matrix);
        }
        return binary2d(mid + 1, end, target, matrix);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = (matrix.size() * matrix[0].size()) -1;
        return binary2d(start, end, target, matrix);
    }
};

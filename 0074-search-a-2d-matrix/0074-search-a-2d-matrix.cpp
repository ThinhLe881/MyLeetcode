class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            int left = 0, right = row.size() - 1;

            if (row[right] < target) {
                continue;
            } else {
                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (row[mid] == target) {
                        return true;
                    } else if (row[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }

        return false;
    }
};
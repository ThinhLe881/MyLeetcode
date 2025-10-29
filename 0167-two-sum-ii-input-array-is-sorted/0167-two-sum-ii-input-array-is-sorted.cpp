class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1, sum = 0;

        while (true) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) {
                return {start+1, end+1};
            }

            if (sum > target) {
                end--;
                continue;
            }

            start++;
        }

        return {};
    }
};
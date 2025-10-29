class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1, sum = 0;
        vector<int> results;

        while (true) {
            sum = numbers[start] + numbers[end];

            if (sum == target) {
                results.push_back(start + 1);
                results.push_back(end + 1);
                break;
            }

            if (sum > target) {
                end--;
                continue;
            }

            start++;
        }

        return results;
    }
};
class Solution {
private:
    vector<vector<int>> ans;

    void dfs(vector<int> &arr, vector<int> &comb, int target, int idx) {
        if (target == 0) {
            ans.emplace_back(comb);
            return;
        }

        if (idx >= arr.size() || target < 0)
            return;

        if (target-arr[idx] >= 0) {
            // Only consider picking the current cadidate if after subtracting it from target, the value is either 
            // positive, or zero. Otherwise we can ignore the current candidate.
            // Choice 1: Pick the current candidate. Then stay at same idx to repick.
            comb.emplace_back(arr[idx]);
            dfs(arr, comb, target-arr[idx], idx);
            comb.pop_back();
        }

        // Choice 3: Skip the current candidate. Then move to next idx.
        dfs(arr,comb,target,idx+1);
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        int idx = 0;
        dfs(candidates, comb, target, idx);
        return ans;
    }
};
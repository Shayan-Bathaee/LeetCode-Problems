// O(N^2) Solution. Looks at every pair of elements until it finds the sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {0, 0}; // initialize a result vector
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (((nums[i] + nums[j]) == target) && (i != j)) {
                    vector<int> result = {i, j};
                    return result;
                }
            }
        }
        return result; // we should never be here
    }
};
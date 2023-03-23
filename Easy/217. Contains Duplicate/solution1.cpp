// This solution runs in O(nlogn) time and has O(1) space complexity. It works by first sorting the array, and then iterating through checking each value's
// neighbor to see if they are equal. If they are, the list contains a duplicate. 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // sort nums
        int loopLen = nums.size() - 1;      // loop 1 less than nums length so we don't over-index array
        for (int i = 0; i < loopLen; i++) {
            if (nums[i] == nums[i + 1]) {   // if element next to nums[i] is the same
                return true;                // there is a duplicate
            }
        }
        return false; // no duplicates
    }
};
// This solution runs in O(n) time and has O(n) space complexity. It works by first setting up a map of the numbers seen, and then adding to the map as we iterate
// through each element in the list. We check if the element has been seen before by searhing it up in the map. Because map accesses are O(1), this has
// no effect on the time complexity.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numsSeen; // set up map containing numbers we've seen
        int numsLen = nums.size();

        for (int i = 0; i < numsLen; i++) { // for every number
            if (numsSeen[nums[i]]) { // if we have seen the number before
                return true; // return true
            }
            numsSeen[nums[i]] = 1; // else mark it seen
        }
        return false; // didn't find a num twice
    }
};
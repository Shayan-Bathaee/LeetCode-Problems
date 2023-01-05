// O(n) Solution. Multiplies the values forward and then backward.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> result; // our return array

        // multiply everything to the left of i into result array
        int product = 1;
        for (int i = 0; i < numsLength; i++) {
            if (i == 0) {
                result.push_back(product);
            }
            else {
                product = product * nums[i - 1];
                result.push_back(product);
            }
        }

        // multiply everything to the right of i into result array
        product = 1;
        for (int i = numsLength - 1; i >= 0; i--) {
            if (i == numsLength - 1) {
                result[i] = result[i] * product;
            }
            else {
                product = product * nums[i + 1];
                result[i] = result[i] * product;
            }
        }

        return result;

    }
};
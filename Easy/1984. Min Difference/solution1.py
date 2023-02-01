# O(N*logN) solution. Sorts the array, and passes through it to find the min difference.

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort() # sort the list in reverse

        
        minDifference = nums[len(nums) - 1] - nums[0]
        # calculate the differences for each window of size k
        # update minDifference if the difference found is smaller
        index = 0
        while (index < (len(nums) - k) + 1):
            window = nums[index:index + k]
            difference = window[k - 1] - window[0]
            if difference < minDifference:
                minDifference = difference
            index += 1

        
        return minDifference
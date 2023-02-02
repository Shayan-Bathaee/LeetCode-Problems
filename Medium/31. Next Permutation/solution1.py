# O(n) solution. Worst case, we have to parse through a list only to find out we need to reverse it. Reversing a list in python is an O(n) operation, 
# and so is parsing through a list.

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
    
        # find i, the first non-sequential element from the back
        i = len(nums) - 2
        while nums[i] >= nums[i + 1] and i != -1:
            i -= 1

        # nums is in reverse order, and thus is the final permutation
        if i == -1:
            return nums.reverse()

        # find rightmost successor to i
        successorIndex = i + 1
        current = i + 1
        while (current < len(nums)):
            if nums[current] > nums[i]:
                successorIndex = current
            current += 1 

        # swap rightmost successor with i
        nums[i], nums[successorIndex] = nums[successorIndex], nums[i]

        # reverse everything after i
        nums[i + 1:len(nums)] = reversed(nums[i + 1:len(nums)])
        





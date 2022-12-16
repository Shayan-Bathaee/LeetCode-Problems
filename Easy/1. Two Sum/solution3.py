# O(N) Solution. Populates a map as it looks through the list, and checks the map to see if the current value's
# complement has already been seen. If so, we return the current index and the complement's index.


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = dict()
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in map:
                return [map[complement], i]
            else:
                map[nums[i]] = i
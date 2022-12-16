# O(N*log(N)) Solution. Sorts a copy of the array and maintains a max/min index until a sum is found.

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numsSorted = nums.copy()
        numsSorted.sort()
        front = 0
        back = len(nums) - 1
        while True:
            sum = numsSorted[front] + numsSorted[back]
            if sum > target: # sum is above our target, decrement the back 
                back -= 1
            elif sum < target: # sum is below our target, decrement the front
                front += 1
            else: # sum is equal to our target. Return
                # edge case: both values are the same
                if (numsSorted[front] == numsSorted[back]):
                    returnList = []
                    returnList.append(nums.index(numsSorted[front])) # get first occurance index
                    nums.remove(numsSorted[front]) # delete first occurance
                    returnList.append(nums.index(numsSorted[back]) + 1) # get second occurance index + 1
                    return returnList
                else:
                    return [nums.index(numsSorted[front]), nums.index(numsSorted[back])]
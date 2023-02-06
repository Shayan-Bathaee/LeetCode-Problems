# Time and space complexity are both O(n) for this solution, because of the part where I build the merged list.
# The idea here is to merge the two lists into one sorted list, and then return the median. Kinda brute force.

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        # combine nums1 and nums2 into one sorted list
        index1 = 0
        index2 = 0
        nums1len = len(nums1)
        nums2len = len(nums2)
        mergedLength = nums1len + nums2len
        mergedList = []
        for i in range(mergedLength):
            if (index1 == nums1len):
                for num in nums2[index2:]:
                    mergedList.append(num)
                break
            if (index2 == nums2len):
                for num in nums1[index1:]:
                    mergedList.append(num)
                break
            if nums1[index1] < nums2[index2]:
                mergedList.append(nums1[index1])
                index1 += 1
            else:
                mergedList.append(nums2[index2])
                index2 += 1
        
        # we now have a merged list. lets find the median
        if mergedLength % 2 == 0:
            return (float(mergedList[mergedLength // 2] + mergedList[(mergedLength // 2) - 1])) / 2
        else:
            return mergedList[(mergedLength // 2)]
            
            
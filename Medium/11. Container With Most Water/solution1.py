# This solution runs in O(n) time and has O(1) space complexity. It takes advantage of the fact the integers in the array placed further apart can 
# contain more water. The algorithm starts at the front and back, closing in on the middle by incrementing front or decrementing back based on whichever
# one is bigger. If we reach a new maximum, we update the largest variable and return it at the end. 

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        back = len(height) - 1
        front = 0
        largest = 0
        while (back > front):
            new = min(height[front], height[back]) * (back - front)
            if new > largest:
                largest = new
            if height[front] < height[back]:
                front += 1
            else:
                back -= 1
        return largest
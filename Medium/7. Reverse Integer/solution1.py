# This solution works by using python's string slicing and typecasting functionalities to turn the int x into a string,
# reverse it, and turn it back into an int. After doing so, the program checks if the result is within the bounds
# and returns the required value. 

class Solution:
    def reverse(self, x: int) -> int:
        # handle negative x
        if x < 0:
            result = int("-" + str(abs(x))[::-1]) # reverse
            if result < -(2**31): # check boundary
                return 0
            return result
        
        # handle positive x
        result = int(str(x)[::-1]) # reverse
        if result > 2**31: # check boundary
            return 0
        return result
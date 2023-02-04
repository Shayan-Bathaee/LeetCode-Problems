# This solution was too slow, it passed 83/98 of the test cases and got hung up on lengthy ones with the failure being 'Time Limit Exceeded'.
# There's certainly room for improvement. Currently, my graph traversals are super basic. Using more optimized algorithms would help time complexity a lot.

class Solution:
    def findLargestCircle(self, favorite):
        largestCircleSize = 0
        
        # starting at every node
        for i in range(len(favorite)):
            # traverse its path until we run into an element again
            visitedIndexes = []
            visiting = i
            while visiting not in visitedIndexes:
                visitedIndexes.append(visiting)
                visiting = favorite[visiting]

            # we ran into an element again. check its value and calculate the size of this circle
            circleSize = len(visitedIndexes) - visitedIndexes.index(visiting)
            
            # reset maxCircleSize if needed
            largestCircleSize = max(largestCircleSize, circleSize)

        return largestCircleSize

    def getMutualFavorites(self, favorite):
        # find all mutual favorites and put them into a set
        mutualFavorites = set()

        # starting at every node
        for i in range(len(favorite)):
            # traverse through that nodes favorites until we see a previously visited node
            visitedIndexes = []
            visiting = i
            while (visiting not in visitedIndexes):
                visitedIndexes.append(visiting)
                visiting = favorite[visiting]
            
            # check index of previously visited node to check if it is a mutual favorite
            if (visitedIndexes.index(visiting) == len(visitedIndexes) - 2):
                mutualFavorites.add(visiting)
                mutualFavorites.add(visitedIndexes[len(visitedIndexes) - 1])
        
        return mutualFavorites
        
    
    def sumAllMutualChains(self, mutualFavorites, favorite):
        # create a dictionary to store the longest chain for each of the nodes
        longestChains = dict()
        for node in mutualFavorites:
            longestChains[node] = 0

        # start at each node and fill in the dictionary
        for i in range(len(favorite)):
            visitedIndexes = []
            visiting = i
            while visiting not in visitedIndexes and visiting not in longestChains:
                visitedIndexes.append(visiting)
                visiting = favorite[visiting]
            if visiting in longestChains:
                if len(visitedIndexes) + 1 > longestChains[visiting]:
                    longestChains[visiting] = len(visitedIndexes) + 1
        
        # add up all the largest chains
        mutualChainSum = 0
        for node in mutualFavorites:
            mutualChainSum += longestChains[node]

        return mutualChainSum


    def maximumInvitations(self, favorite: List[int]) -> int:
        # find two things: the largest circle, and the sum of all chains containing a mutual pair

        # largest cicle
        largestCircleSize = self.findLargestCircle(favorite)

        # sum of all  chains containing a mutual pair
        mutualFavorites = self.getMutualFavorites(favorite)
        mutualChainSum = self.sumAllMutualChains(mutualFavorites, favorite)

        return max(mutualChainSum, largestCircleSize)

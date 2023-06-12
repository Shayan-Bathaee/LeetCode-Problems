# A bit of a brute force solution. generate() builds the first row, then calls generate_next for every following row. 
# generate_next takes in the previous row, and builds the next one by adding the 'parent' elements in the previous row.

class Solution:
    def generate_next(self, row):
        result = [1]
        for i in range(len(row) - 1):
            result.append(row[i] + row[i + 1])
        result.append(1)
        return result

    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1]]
        for i in range(numRows - 1):
            result.append(self.generate_next(result[i]))
        return result


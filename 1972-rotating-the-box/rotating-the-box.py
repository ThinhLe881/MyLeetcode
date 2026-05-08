class Solution(object):
    def rotateTheBox(self, boxGrid):
        """
        :type boxGrid: List[List[str]]
        :rtype: List[List[str]]
        """
        # init empty box
        m = len(boxGrid)
        n = len(boxGrid[0])
        result = [["." for _ in range(m)] for _ in range(n)]

        for i in range(m):
            lowest_row_with_empty_cell = n - 1
            for j in range(n - 1, -1, -1):
                # found a stone - let it fall to the lowest empty cell
                if boxGrid[i][j] == "#":
                    result[lowest_row_with_empty_cell][m - i - 1] = "#"
                    lowest_row_with_empty_cell -= 1
                # found an obstacle - reset `lowest_row_with_empty_cell` to the row directly above it
                if boxGrid[i][j] == "*":
                    result[j][m - i - 1] = "*"
                    lowest_row_with_empty_cell = j - 1

        return result
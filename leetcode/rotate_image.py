class Solution(object):
    def rotate(self, matrix):
        """
        You are given an n x n 2D matrix representing an image.
        Rotate the image by 90 degrees (clockwise). You must do this in-place.

        Time complexity: O(N)
        Space complexity: O(1)

        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        start = 0
        n = len(matrix) - 1     # The length of the initial matrix
        end = n

        # If there are values between the start and end
        while end - start >= 1:
            for j in range(start, end):
                temp = matrix[start][j]
                matrix[start][j] = matrix[n - j][start]
                matrix[n - j][start] = matrix[n - start][n - j]
                matrix[n - start][n - j] = matrix[j][n - start]
                matrix[j][n - start] = temp

            # Traverse diagonally
            start += 1
            end -= 1


s = Solution()
i = [
  [5, 1, 9, 11],
  [2, 4, 8, 10],
  [13, 3, 6, 7],
  [15, 14, 12, 16]
]
s.rotate(i)
print(i)


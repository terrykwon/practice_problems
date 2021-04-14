class Solution(object):
    def plusOne(self, digits):
        """Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
        You may assume the integer do not contain any leading zero, except the number 0 itself.
        The digits are stored such that the most significant digit is at the head of the list.

        :type digits: List[int]
        :rtype: List[int]
        """
        if digits[-1] != 9:
            digits[-1] += 1
            return digits
        elif digits[:-1]:
            return self.plusOne(digits[:-1]) + [0]
        else:
            return [1, 0]

s = Solution()

arr = [9, 9, 9, 8]
print(s.plusOne(arr))

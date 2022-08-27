class Solution(object):
    def reverseString(self, s):
        """
        Write a function that takes a string as input and returns the string reversed.
        
        :type s: str
        :rtype: str
        """

        res = []
        for i in range(len(s) - 1, -1, -1):
            res.append(s[i])

        return ''.join(res)

    def reverseString2(self, s):
        """
        A simpler solution
        """
        return s[::-1]

s = Solution()
print(s.reverseString('hello'))
print(s.reverseString2('hello'))
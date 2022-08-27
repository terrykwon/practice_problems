class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        Write a function to find the longest common prefix string amongst an array of strings.
        i.e.) All strings in the array must contain the prefix.
        
        Time complexity:    O(N * L), where N is the number of strings and L is the maximum length.
        Space complexity:   O(1), since one character at a time is compared.
        
        :type strs: List[str]
        :rtype: str
        """

        prefix = ''

        if len(strs) == 0:
            return 0

        for i in range(len(strs[0])):
            char = strs[0][i]

            for j in range(1, len(strs)):
                if len(strs[j]) <= i or strs[j][i] != char:
                    return prefix

            prefix += char

        return prefix


s = Solution()

s1 = 'hellohahaha'
s2 = 'hehahahedgehoghello'
s3 = 'heatwhat'
s4 = 'hehe'

arr = [s1, s2, s3, s4]
print(s.longestCommonPrefix(arr))
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        res = '1'
        print(res)
        for i in range(1, n):
            res = self.count(res)
            print(res)

        return res

    def count(self, seq):
        digit = seq[0]
        res = ''
        i = 1
        count = 1

        while i < len(seq):
            # if the next digit is different
            if digit != seq[i]:
                res += (str(count) + str(digit))
                digit = seq[i]
                count = 1
            else:
                count += 1

            i += 1

        # For last iteration. Probably can be cleaner.
        res += (str(count) + str(digit))

        return res





sol = Solution()
# print(sol.count(5))

sol.countAndSay(2)




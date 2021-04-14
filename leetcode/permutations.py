class Solution(object):
    def permute(self, nums):
        """
        Given a collection of distinct numbers, return all possible permutations.
        
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1:
            return [nums]

        results = []

        for i in nums:
            remaining = [x for x in nums if x != i]

            for t in self.permute(remaining):
                results.append([i] + t)

        return results


sol = Solution()

p1 = [1,2,3]

s1 = [[1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]]

assert sol.permute(p1) == s1

print(sol.permute(p1))

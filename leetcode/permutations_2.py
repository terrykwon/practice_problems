class Solution(object):
    def permuteUnique(self, nums):
        """
        Given a collection of numbers that might contain duplicates, return all possible unique permutations.

        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1:
            return [nums]

        results = []

        for i in range(len(nums)):
            remaining = [x for x in nums]
            del remaining[i]

            for t in self.permuteUnique(remaining):
                results.append([i] + t)

        return results


sol = Solution()
print(sol.permuteUnique([1,1,2]))
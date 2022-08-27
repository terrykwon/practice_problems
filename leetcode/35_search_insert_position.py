class Solution(object):
    def searchInsert(self, nums, target):
        """
        Given a sorted array and a target value, return the index if the target is found. 
        If not, return the index where it would be if it were inserted in order.
        You may assume no duplicates in the array.

        :type nums: List[int]
        :type target: int
        :rtype: int
        
        Time complexity: O(N)
        
        Improvements: Using binary search can reduce to time to O(log(N))
        """

        index = 0

        while index < len(nums) and nums[index] < target:
            index = index + 1

        return index


s = Solution()

nums = [1, 2, 3, 7]
target = 5

print(s.searchInsert(nums, target))
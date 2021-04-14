class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        Find the medium of two sorted arrays.
        
        Time complexity: O(N), where N is the length of the combined array.
        Space complexity: O(N)
        
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        length = len(nums1) + len(nums2)

        combined = []

        i1 = 0
        i2 = 0

        for i in range(0, length):
            if i1 >= len(arr1):
                combined.append(arr2[i2])
                i2 += 1
                continue
            elif i2 >= len(arr2):
                combined.append(arr1[i1])
                i1 += 1
                continue

            if arr1[i1] < arr2[i2]:
                combined.append(arr1[i1])
                i1 += 1
            else:
                combined.append(arr2[i2])
                i2 += 1

        if length % 2 == 0:
            # Length is even
           median = (combined[(length // 2) - 1] + combined[length // 2]) / 2
        else:
            # Length is odd
            median = combined[(length // 2) + 1]

        print(combined)
        return median

    def findMedianSortedArrays2(self, nums1, nums2):
        # A recursive solution
        # TODO: SOLVE
        if len(nums1) + len(nums2) == 0:
            return None

        if len(nums1) + len(nums2) == 1:
            # Return median of these numbers
            return (nums1 + nums2)[0]

        if len(nums1) + len(nums2) == 2:
            return ((nums1 + nums2)[0] + (nums1 + nums2)[1]) / 2

        if len(nums1) + len(nums2) == 3:
            return sorted(nums1 + nums2)[1]

        if len(nums1) + len(nums2) == 4:
            arr = sorted(nums1 + nums2)
            return (arr[1] + arr[2]) / 2

        med1 = len(nums1) // 2
        med2 = len(nums2) // 2

        if nums1[med1] > nums2[med2]:
            return self.findMedianSortedArrays2(nums1[:med1], nums2[med2:])
        else:
            return self.findMedianSortedArrays2(nums1[med1:], nums2[:med2])




s = Solution()

arr1 = [1, 2]
arr2 = [4, 5, 6, 7, 11, 13, 15]

print(sorted(arr1 + arr2))
print(s.findMedianSortedArrays2(arr1, arr2))
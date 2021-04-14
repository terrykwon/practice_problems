class Solution(object):
    def hammingDistance(self, x, y):
        """
        The Hamming distance between two integers is the number of positions 
        at which the corresponding bits are different.
        
        :type x: int
        :type y: int
        :rtype: int
        """
        # Convert ints to 32 bit string representation
        bin_x = bin(x)[2::].zfill(32)
        bin_y = bin(y)[2::].zfill(32)

        print(bin_x)
        print(bin_y)

        count = 0

        for i in range(32):
            if bin_x[i] != bin_y[i]:
                count += 1

        return count

    def hammingDistance2(self, x, y):
        return bin(x ^ y).count('1')



s = Solution()
i1 = 4
i2 = 1

print(s.hammingDistance(i1, i2))
print(s.hammingDistance2(i1, i2))
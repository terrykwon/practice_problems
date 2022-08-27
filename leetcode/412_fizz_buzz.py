class Solution(object):
    def fizzbuzz(self, n):
        """
        
        Write a program that outputs the string representation of numbers from 1 to n.

        But for multiples of three it should output “Fizz” instead of the number 
        and for the multiples of five output “Buzz”. 
        For numbers which are multiples of both three and five output “FizzBuzz”.

        :type n: int
        :rtype: List[str]
        """

        res = []

        for i in range(1, n + 1):
            if i % 15 == 0:
                res.append('FizzBuzz')
                continue
            elif i % 3 == 0:
                res.append('Fizz')
                continue
            elif i % 5 == 0:
                res.append('Buzz')
                continue
            res.append(str(i))

        return res

s = Solution()
print(s.fizzbuzz(15))
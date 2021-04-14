import copy


class Solution(object):
    mappings = {
        '2': {'a', 'b', 'c'},
        '3': {'d', 'e', 'f'},
        '4': {'g', 'h', 'i'},
        '5': {'j', 'k', 'l'},
        '6': {'m', 'n', 'o'},
        '7': {'p', 'q', 'r', 's'},
        '8': {'t', 'u', 'v'},
        '9': {'w', 'x', 'y', 'z'}
    }

    def letterCombinations(self, digits):
        """
        Given a digit string, return all possible letter combinations that the number could represent.

        A mapping of digit to letters (just like on the telephone buttons) is given below.

        Time complexity: O(3^N), where N is the number of digits (roughly, since some digits have 4 characters).
        Space complexity: O(N * 3^N)
        
        :type digits: str
        :rtype: List[str]
        """
        res = []
        if len(digits) == 0:
            return res
        self.combinations(digits, res, "")

        return res

    def combinations(self, digits, res, temp):
        if len(digits) == 0:
            res.append(temp)
            return

        for c in self.mappings[digits[0]]:
            strcopy = copy.deepcopy(temp)
            strcopy += c
            self.combinations(digits[1:], res, strcopy)


s = Solution()
print(s.letterCombinations('237'))

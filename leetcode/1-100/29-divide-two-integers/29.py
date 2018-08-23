class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        res = int(dividend / divisor)
        if res > 2147483647 : res = 2147483647
        if res < -2147483648 : res = -2147483648
        return res

a = Solution()
print (a.divide(1,2))

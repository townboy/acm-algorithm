class Solution(object):
    def isPalindrome(self, x):
        num = str(x)
        return True if num == num[::-1] else False

class Solution(object):
    def singleNumber(self, A):
        hashtable = dict()
        for digit in A:
            if None != hashtable.get(digit, None):
                hashtable[digit] = True
            else:
                hashtable[digit] = False
        for (k, v) in hashtable.items():
            if False == v:
                return k

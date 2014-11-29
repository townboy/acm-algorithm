#!/usr/bin/env python
# -*- coding:utf8 -*-
class Solution(object):
    def reverse(self, x):
        MAX = 2 ** 31 - 1
        MIN = - 2 ** 31
        if x >= 0:
            result = str(x)[::-1]
        else:
            result = '-' + str(-x)[::-1]
        result = int(result)
        if result <= MAX and result >= MIN:
            return result
        return 0


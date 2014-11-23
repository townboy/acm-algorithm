class Solution:
    def twoSum(self, num, target):
        ci = [i + 1 for i in range(len(num))]
        num_dict = dict(zip(num, ci))
        for i in range(len(num)):
            pos = num_dict.get(target - num[i], None)
            if pos and pos != i + 1:
                return (i + 1, num_dict[target - num[i]])
                  
if __name__ == '__main__':
    run = Solution()

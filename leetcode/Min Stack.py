class MinStack(object):
    def __init__(self):
        self.stack = []
        self.minstack = []
        self.idx = 0
        
    def push(self, x):
        if self.minstack:
            if x < self.minstack[-1][1]:
                self.minstack.append([self.idx , x])
        else:
            self.minstack.append([self.idx , x])
        self.stack.append(x)
        self.idx = self.idx + 1
            
        
    def pop(self):
        self.idx = self.idx - 1
        if self.idx == self.minstack[-1][0]:
            del self.minstack[-1]
        del self.stack[-1]
    
    def top(self):
        return self.stack[-1]

    def getMin(self):
        return self.minstack[-1][1]


from collections import deque
class MaxStack:
    def __init__(self):
        self.stack = deque() # stores every elements with incoming order
        self.maxStack = deque()  # stores every large element we've seen
        
    def push(self, x) -> None:
        self.stack.append(x)
        if not self.maxStack or x >= self.maxStack[-1]:
            self.maxStack.append(x)
    
    def pop(self) -> int:
        val = self.stack.pop()
        if val == self.maxStack[-1]:
            self.maxStack.pop()
        return val

    def top(self) -> int:
        return self.stack[-1]

    def peekMax(self) -> int:
        return self.maxStack[-1]

    def popMax(self) -> int:
        lastMax = self.maxStack.pop() 
        tmp = deque()
        while self.stack[-1] != lastMax:
            tmp.append(self.stack.pop())
        self.stack.pop()
        '''
        lastMax: 5
        '''
        
        while tmp:
            val = tmp.pop()
            self.stack.append(val)
            if not self.maxStack or val >= self.maxStack[-1]:
                self.maxStack.append(val)
        return lastMax

# [push 5, push 1, top(), popMax()]
# after 2 push: stack [5, 1], maxStack [5]
# top: 1
# popMax(): 


maxStack = MaxStack()
maxStack.push(1)
maxStack.push(2)
print(maxStack.top())


# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
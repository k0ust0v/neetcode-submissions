class MinStack:
# The logic is we will append the element and the current min
# as a tuple
    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        if not self.stack:
            self.stack.append((val,val))
        else:
            tempMin = self.stack[-1][1]
            if tempMin < val:
                self.stack.append((val,tempMin))
            else:
                self.stack.append((val,val))

    def pop(self) -> None:
        del self.stack[-1]

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]

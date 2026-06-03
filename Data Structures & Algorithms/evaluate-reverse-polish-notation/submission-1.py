class Solution:

    def evalRPN(self, tokens: List[str]) -> int:
        add = lambda x, y: x+y
        sub = lambda x,y: x-y
        mul = lambda x,y: x*y
        div = lambda x,y: int(x/y) # Truncates toward zero as required
        op = ['+','-','*','/']
        d = deque()

        for t in tokens:
            if t not in op:
                d.append(int(t))
            else:
                v2 = d.pop() #right op
                v1 = d.pop() #left op
                if t == "+":
                    r = add(v1,v2)
                elif t == "-":
                    r = sub(v1,v2)
                elif t == "*":
                    r = mul(v1,v2)
                elif t == "/":
                    r = div(v1,v2)
                d.append(r)
        
        return d.pop()


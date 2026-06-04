class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0]*len(temperatures)

        for i,t in enumerate(temperatures):
            while stack and t > stack[-1][1]:
                index, val = stack.pop()
                res[index] = i - index
            stack.append((i, t))

        return res

MX = 1000001
factors = [[] for _ in range(MX)]

for i in range(2, MX):
    if not factors[i]:
        for j in range(i, MX, i):
            factors[j].append(i)

class Solution(object):
    def minJumps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        edges = defaultdict(list)

        for i, a in enumerate(nums):
            for p in factors[a]:
                edges[p].append(i)
        
        res = 0
        seen = [False] * n
        seen[0] = True
        q = [0]

        while True:
            q2 = []

            for i in q:
                if i == n - 1: # reach the end
                    return res

                if i > 0 and not seen[i - 1]:
                    seen[i - 1] = True
                    q2.append(i - 1)

                if i < n - 1 and not seen[i + 1]:
                    seen[i + 1] = True
                    q2.append(i + 1)

                if len(factors[nums[i]]) == 1:
                    p = nums[i]

                    for j in edges[p]:
                        if not seen[j]:
                            seen[j] = True
                            q2.append(j)

                    edges[p] = []
            
            q = q2
            res += 1
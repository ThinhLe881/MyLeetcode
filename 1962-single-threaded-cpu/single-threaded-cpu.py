class Solution(object):
    def getOrder(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: List[int]
        """
        n = len(tasks)
        tasks = [(t[0], t[1], i) for i, t in enumerate(tasks)]
        tasks.sort()
        heap = []
        time = 0
        res = []
        i = 0

        while len(res) < n:
            while i < n and tasks[i][0] <= time:
                heapq.heappush(heap, (tasks[i][1], tasks[i][2]))
                i += 1

            if not heap:
                if i < n:
                    time = tasks[i][0]
            else:
                p, index = heapq.heappop(heap)
                time += p
                res.append(index)
                
        return res
        
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        distinct_set = set()

        for num in nums:
            if num in distinct_set:
                return True
            
            distinct_set.add(num)

        return False
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        freqS, freqT = {}, {}

        for i in range(len(s)):
            freqS[s[i]] = 1 + freqS.get(s[i], 0)
            freqT[t[i]] = 1 + freqT.get(t[i], 0)
        
        return freqS == freqT
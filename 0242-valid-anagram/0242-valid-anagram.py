class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        charfreqs={}
        charfreqt={}
        for char in s:
            charfreqs[char]=charfreqs.get(char,0)+1
        for char in t:
            charfreqt[char]=charfreqt.get(char,0)+1        

        if charfreqs==charfreqt:
            return True
        else:
            return False
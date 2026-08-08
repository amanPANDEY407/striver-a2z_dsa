class Solution:

    def frequencySort(self,s:str) -> str:
        freq={}
        for char in s:
            freq[char]=freq.get(char,0)+1

        sorted_data = dict(sorted(freq.items(), key=lambda x: x[1],reverse=True))
        a=""
        for elem in sorted_data:
            
            a+=sorted_data[elem]*elem

        return a
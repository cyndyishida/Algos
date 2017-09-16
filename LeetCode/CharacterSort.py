from operator import itemgetter 
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        frequency = {}
        for i in s:
            if i in frequency:
                frequency[i] += 1
            else:
                frequency[i] = 1
        
        return "".join( [ i[0]*i[1] for i in sorted([(key,value) for key,value in frequency.items() ] , key=itemgetter(1), reverse = True)])
        
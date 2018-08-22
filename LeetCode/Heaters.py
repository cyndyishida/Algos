class Solution:
    
    def binSearch(self, heaters, house):
        low = 0
        high = len(heaters) - 1

        max_rad = 99999999999999
        while high >= low:
            mid = low + ( high - low ) // 2
            
            curr_diff =abs(house - heaters[mid])
            max_rad = min(max_rad, curr_diff)
            if max_rad == 0:
                return max_rad
            if house > heaters[mid]:
                low = mid +1
            else:
                high = mid - 1

        return max_rad
        
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters.sort() 
        return max(self.binSearch(heaters, i ) for i in houses)
            
                    
                
        
        
        
            

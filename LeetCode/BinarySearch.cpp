class Solution {
public:
    int search(vector<int>& nums, int target) {
        size_t begin, end, mid; 
        begin = 0;
        mid = 0;
        end = nums.size() ;
        bool not_found = true;
        while ( end > begin && not_found ){
            mid = (end  +  begin )/ 2; 
            if (nums[mid] == target) not_found = false; 
            else {
                if( nums[mid] > target ) end = mid;
                else begin = mid +1;
            }
            
            
        }
        
        
        return not_found?  -1 : mid;
    }
};

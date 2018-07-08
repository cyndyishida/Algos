class Solution {
public:
    int findMin(vector<int>& nums) {
        
        bool found = false;
        
        int i = 0;
        for (; i < nums.size() -1 && !found ; ++i)
        {
            if(nums[i] > nums[i+1])
                found = true;
            
        }
        
        return found? nums[i] : nums[0];
        
        
    }
};

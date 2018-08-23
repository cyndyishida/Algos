class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0; 
        int lhs_sum = 0; 
        int rhs_sum = accumulate(nums.begin(), nums.end(), 0 );
        
        for(i= 0; i < nums.size(); ++i)
        {
            //cout << nums[i];
            //cout << " lhs: " << lhs_sum << " rhs: " << rhs_sum << endl; 
            rhs_sum -= nums[i];
            
            if (lhs_sum == rhs_sum)
            {
                return i ;
            }
            lhs_sum += nums[i];
            
            
        }
        
        return -1;
        
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        generate(nums, 0, nums.size()-1 , result);
        
        return result;
        
    }
    
    
    
    void generate(vector<int>& nums, int start, int left, vector<vector<int>>& result )
    {
        if (start == left)
        {
            result.push_back(nums);
            return ;
        }
        for (int i = start; i <= left ; ++i)
        {
            swap(nums[start], nums[i] );
            generate(nums, start +1, left, result );
            swap(nums[start], nums[i]);
        }
        
    }
    
    
};




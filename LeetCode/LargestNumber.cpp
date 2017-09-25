class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vals;
        std::transform(nums.begin(), nums.end() , std::back_inserter(vals),
                      [](const int& n) ->string {return to_string(n);});
        
        sort(vals.begin(), vals.end() ,[](string &s1, string &s2){ return s1+s2>s2+s1; });
        
        
        string result = ;
        
        for(auto el: vals)
            result += el;
        
        uint8_t i = 0;
        bool all_zeros = false;
        
        while(i < result.size() && result[i++] == '0' )
            all_zeros = true;
        
        
        if (i == result.size() && all_zeros)
            result = 0;
        
        
        return result;
        
        
        
        
    }
};

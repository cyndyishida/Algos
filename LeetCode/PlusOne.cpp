class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; 
        bool keep_going = true; 
        for(int i = digits.size() -1; i >= 0 && keep_going; --i)
        {
            if(digits[i] + carry != 10 )
            {
                digits[i] = digits[i] +1 ;
                keep_going = false; 
            }
            else
            {
                digits[i] = 0; 
            }
        }
        
        if (keep_going)
            digits.insert(digits.begin(), 1);
        
        
        return digits;
    }
};

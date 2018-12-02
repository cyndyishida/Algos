class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        
        uint64_t unique_count = 0; 
        int sum, n_mult, i, temp; 
        for (i = n; i > 0; --i, sum = 1, n_mult = 9 ) {
            for (temp =0; temp < i; ++temp ) {
                if (temp <2) sum *= 9;
                else  sum *= --n_mult;
            }
            unique_count += sum;
        }
        
        return unique_count + 1;
    }
};

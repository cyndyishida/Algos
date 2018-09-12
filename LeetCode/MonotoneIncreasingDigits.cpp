class Solution {
public:


    int monotoneIncreasingDigits(int N) {

        std::string result(std::to_string(N));
        bool isMono = true;
        size_t i = 0;
        
        for (; i < result.size() - 1 && isMono; ++i)
        {

            if(result[i] > result[i+1])
            {
                result[i] -= 1 ;

                if ( (i > 0  && result[i - 1] <= result[i] ) || i == 0) isMono = false;
                else i -= 2;
            }
        }

        if (!isMono)
            for (; i < result.size() ; ++i) result[i] = '9';

        return std::stoi(result);
    }
};

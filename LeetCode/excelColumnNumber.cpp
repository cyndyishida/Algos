class Solution {
public:
    int titleToNumber(string s) {
        static int VAL = 26;
        int count = 0;
        if (s.size() != 0 )    
        {
            
            int j = 0;
            for (int i = (s.size() -1) ; i >= 0 ; --i, ++j)
            {
                VAL = pow(26, j);
                if (i == s.size() - 1 )
                    count += ((s[i] - 'A') + 1);
                else 
                    count += (VAL  * ( (s[i] - 'A') + 1)  );
            }
                
            
        }
        return count;
        
    }
};

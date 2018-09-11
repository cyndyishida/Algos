class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        
        bool isMono = true;
        
        for (int i = 0; i < A.size() - 1  && isMono; ++i)
        {
            if (A[i +1 ] < A[i] )
                isMono = false; 
        
        }
        
        
        if (!isMono)
        {
            isMono = true; 
            for (int i = 0; i < A.size() - 1  && isMono; ++i)
            {
                if (A[i +1 ] > A[i] )
                    isMono = false; 

            }

            
        }
        return isMono;
        
        
        
        
    }
};

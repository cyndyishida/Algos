class Solution {
public:
    
    // 
    vector<int> countBits(int num) {

        vector<int> counters(num + 1, 0); 
        for(int i = num; i >= 0; --i)
        {
            int val = i, counter = 0;

            
            while(val > 0 )
            {
                counter += (val % 2);
                val /=2;



            }
            counters[i] = counter;
        }
        
        return counters;
        
    }
};

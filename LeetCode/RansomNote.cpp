class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     
        std::unordered_map<char, size_t> M_freq;    
        for (auto el : magazine) ++M_freq[el];
        
        
        
        bool CanConstruct = true;
        for (size_t i = 0; i < ransomNote.size()  && CanConstruct  ; ++i)        
        {
            if (M_freq.find(ransomNote[i]) != M_freq.end())
            {
                if (M_freq[ransomNote[i]] == 0)
                    CanConstruct = false; 
                else 
                    --M_freq[ransomNote[i]];
            }
            else CanConstruct = false; 
        }
            
            
        return CanConstruct;
        
        
        
        
        
    }
};

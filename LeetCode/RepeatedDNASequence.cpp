class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::unordered_map<std::string, int> freq;
        std::vector<std::string> words;       
        for (int i = 0; i <= static_cast<int>(s.size()) - 10 ; ++i)
            freq[s.substr(i,10)]++;
        
        

        for(auto el : freq)
            if(el.second  > 1 ) 
                words.emplace_back(el.first);
        
        
        return words;
        
        
    }
};

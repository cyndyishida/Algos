class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";
    if(!strs.empty())
    {
        auto max = std::min_element(strs.begin(), strs.end(), 
                 [](const string & a , const string &b )-> bool 
                    {return a.size() < b.size();})->size();
        
        bool stop = false; 
        char cur= 'a';
        for (size_t i = 0 ; i < max && !stop ; ++i)
        {
            cur = strs[0][i];
            for (int w = 1; w < strs.size() ; ++w)
            {
                if (strs[w][i] != cur)
                    stop = true; 
            }
            if (!stop)
                prefix += cur;
        }
        
        
        
    }
        

        
        
     return prefix;   
    }
};

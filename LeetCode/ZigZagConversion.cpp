#include <string>
#include <vector>
using Matrix = std::vector<std::vector<char>>;
class Solution {
public:
    string convert(string s, int numRows) {
        
        Matrix preset(numRows); 
        std::vector<char> load( s.size()/2  ,'0');
        
        for(uint8_t i = 0; i < numRows; )
            preset.emplace_back(load);
        
        bool zag = false; 
        uint8_t row, col = 0;
        for (uint8_t j = 0; j < s.size() ; ++j)
        {
            if (j % row && !j )
            {
                row = numRows - 2;
                zag = true;
                preset[row][col++] = s[j];
            }
            else if (!zag && row <= numRows -1)
                preset[row++][col] = s[j];
            else 
            {
                ++col;
                if (row)
                {
                    --row;  
                    preset[row][col] = s[j];
                }
                else
                {
                    row = 0;
                }
                
            }    
        }
        
        for (auto vec : preset)
        {
            for (auto ch : vec)
                cout << ch ;
            cout << endl;    
        }
        
        
        return "mom";
        
        
    }
};

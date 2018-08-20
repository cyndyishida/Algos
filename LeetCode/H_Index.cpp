class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (!citations.empty())
        {
            std::sort(citations.begin(), citations.end());
            for(int i = 0; i < citations.size(); ++i)
            {
                int curr = citations[i];
                int h_index = citations.size() - i;
                
                if (h_index <= curr)
                    return h_index;
            }
        }
        return 0; 

    }
};

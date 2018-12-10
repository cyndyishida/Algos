class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int capable = 0;
        bool can_change =false;
        for (int i = 0; capable < n && i + 1 < flowerbed.size(); ++i, can_change = false) {
            // first element bound 
            if (i == 0  && !flowerbed[i] && !flowerbed[i+1]) can_change = true;
            else if (!flowerbed[i]  && !flowerbed[i+1] && !flowerbed[i-1]) can_change = true;
            if (can_change) {
                flowerbed[i] = 1;
                ++capable; 
            }
        }
        // last element bound 
        if (!flowerbed[flowerbed.size() -1] && !flowerbed[flowerbed.size() - 2]) {
            ++capable;
        }
        
        
        return capable >= n;
    }
};

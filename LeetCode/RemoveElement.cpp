//Algorithm: O(N) runtime O(1) space. 
//iterate through the array, for each element that is the value swap 
// with whatever is at the start of the array, 
// iterate that placeholder, and when your done,
// each swap accumulated is the range of elements to remove,
// allowing to batch delete. 

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      auto start = nums.begin();
      for (auto curr = start; curr != nums.end(); ++curr) {
        if(*curr == val) {
          std::swap(*curr, *start);
          start++;
        }
      }
      nums.erase(nums.begin(), start);
      return nums.size();
    }
};

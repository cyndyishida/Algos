/*
 Part 1. given a string return the sorted index of all of it's suffix's, 
 Part 2. given the list of suffixes & a needle string, return a boolean whether the needle word
 exists within the original string 
*/

#include <iostream> #include <vector> 
#include <string>
#include <string_view>
#include <utility>
// runtime : O(n^2 log(n))
// space : O(n)
std::vector<int> sortedSuffixes(const std::string_view word) {
    std::vector<std::pair<std::string_view, int>> suffixes;
    suffixes.reserve(word.size());
    for(auto i = 0; i < word.size(); ++i) {
        suffixes.push_back({word.substr(i, word.size() - i ), i});
    }
    
    std::sort(suffixes.begin(), suffixes.end(),
        [](const auto& a, const auto& b){ 
                                    return a.first < b.first;}); 

    std::vector<int> result; result.reserve(word.size());
    for (const auto& el : suffixes) result.push_back(el.second);
    return result;
}



int reverse(int n) {
  int result = 0;
  for( auto i = 0 ; i < sizeof(n) * 8 ; ++i ) {
    result = result << 1;
    result |= ( n & 1);
    n = n >> 1;
    ++i;
  }

  return result;
}

int main () {
    int x = 5; 
    std::cout << reverse(x) << std::endl;    

    return 0;
}

/*
 Part 1. given a string return the sorted index of all of it's suffix's, 
 Part 2. given the list of suffixes & a needle string, return a boolean whether the needle word
 exists within the original string 
*/

#include <iostream>
#include <vector> 
#include <string>
#include <string_view>
#include <utility>

std::vector<int> sortedSuffixes(const std::string_view word) {
    std::vector<std::pair<std::string_view, int>> suffixes;
    suffixes.reserve(word.size());
    for(auto i = 0; i < word.size(); ++i) {
        suffixes.push_back({word.substr(i, word.size() - i ), i});
    }
    
    std::sort(suffixes.begin(), suffixes.end(), [](const auto& a, const auto& b ){return a.first < b.first;}); 

    std::vector<int> result; result.reserve(word.size());
    for (const auto& el : suffixes) result.push_back(el.second);
    for (const auto& el : suffixes) std::cout << el.first << std::endl;
    return result;
}




int main () {

    sortedSuffixes("abcd");
    return 0;
}

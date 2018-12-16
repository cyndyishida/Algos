
#include <iostream>
#include <vector> 
#include <string>
#include <string_view>
#include <utility>


// Slow solution 
int reverse(int n) {
  int result = 0;
  for( auto i = 0 ; i < sizeof(n) * 8 ; ++i ) {
    result = result << 1;
    result |= ( n & 1);
    n >>= 1;
  }

  return result;
}

int main () {
    int x = 2; 
    std::cout << reverse(x) << std::endl;    

    return 0;
}

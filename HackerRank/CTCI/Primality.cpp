/*
    - take sqaure root of num,
    - for 2 up to the sqaured value
    - it's not divisble by 2 its not problem
    - at the end check to see that n isn't 1
        and the difference between the ceiling of the square root and square root is 0 
*/

#include <cmath>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


string is_prime(int n)
{
    
    double shorter = sqrt(n);
    
        
    for(int i = 2; i < ceil(shorter) ; ++i)
        if (!(n % i) )
          return "Not prime";
    
    return n == 1 ||  abs( shorter - ceil(shorter) ) < 0.001   ? "Not prime": "Prime";
    
    
    
}


int main(){
    int p,n;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        cin >> n;
        cout << is_prime(n) << endl;
        
    }   
    return 0;
}

#include <iostream>


int64_t findAllOnes( int64_t n ) {

    int sum; 
    for(int i = 0; i < sizeof(n)* 8 ; ++i) {
        sum += n & 1; // bitmask off last bit 
        n >>= 1; // shift bits over; 

    } 
    return sum;
}




int main (){
    std::cout <<  findAllOnes(1) << std::endl; 
    std::cout <<  findAllOnes(-2) << std::endl; 
    std::cout <<  findAllOnes(3) << std::endl; 
    std::cout <<  findAllOnes(4) << std::endl; 
    std::cout <<  findAllOnes(5) << std::endl; 

    return 0;
}

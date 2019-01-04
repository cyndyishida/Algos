#include <iostream> 

int invert(int value, int pos, int count) {
    int result;  
    int numOfBits = sizeof(value) * 8; 
    std::cout << numOfBits << std::endl;
    for (auto i = 0; i < numOfBits; ++i) {
        if ( i >= pos && i < pos + count) {
           // get bit from index in the right side indexing and negate it  
           bool currBit = ~((value >> i) & 1);
           std::cout << i << " "  << currBit << std::endl; 
        } else {

        }
    } 
    
    return 0; 
}

//before = 1110 1110
//pos = 3 
//count = 3 
//after =    11 [  010 ] 110


//invert(142, 3, 3) = 182

int main () {

    std::cout << invert(142,3,3) << std::endl;

    return 0; 
}



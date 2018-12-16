#include <iostream> 


//int getByte(int x, int n) {
//    int result=0;
//    int i = 0;
//    // remove out the right most 8 * n bits to get to the byte we want 
//    while (i < n) {
//        x >>= 8;
//        ++i;
//    }
//    
//    // get last 8 bits 
//    return x  & 0xFF;
//}

int getByte(int x, int n) {
    // this shifts out n relative to what n * 8 would be 
    x >>= (n << 3);
    return x & 0xFF;
}

int main () {

    int x, n; 
    // extract byte n from int x 

    //getByte(0x12345678,1) ret: 0x56

    std::cout << getByte(305419896,1) << std::endl;




    return 0;
}

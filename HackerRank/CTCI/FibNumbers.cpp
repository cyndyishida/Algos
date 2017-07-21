/*
    fib sequence memotized 
    - a, b start of as fib(0)  & fib(1)
    - c in the the loop is the sum
    - a is the old b
    - b is the old c
    return n if basecase else return C 
*/

#include <iostream>

using namespace std;

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n ; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    
    return n < 2? n : c;

}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

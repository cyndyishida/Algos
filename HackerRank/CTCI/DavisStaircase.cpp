/*
    Same as fib 
*/
#include <cmath>
#include <stack>
#include <vector>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;


int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        
        
             
        if (n < 3 ) cout <<  n << endl;
        else{
            int step_1 = 1;
            int step_2 = 2; 
            int step_3 = 4;
            int all;
            for (int i = 4; i <= n ; ++i )
            {   
               all =  step_1 + step_2 + step_3;
               step_1 = step_2;
               step_2 = step_3; 
               step_3 = all;
                
            } 
        
            cout << step_3 << endl;
        
        }
        
        
        
    }
    return 0;
}

/*
 given the first two values 
 take the smaller one and put it in the max heap, other in min
 
 for each item, 
    - if the value is smaller than the max heap, insert, else put in the other one.
    - if the size diff ever gets greater than 1, take the heap with more and pop the root & add to the other one
 
 median is always the root with the larger size or if equal, the median of the 2 roots 

 
*/


#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

using MaxHeap = priority_queue<int>;
using MinHeap = priority_queue<int, vector<int>, greater<int>>;

double median(double a, double b)
{
    return (a + b) /2;
}

double median(const MaxHeap& max, const MinHeap& min)
{
    return max.size() > min.size() ? max.top() : min.top();
}

int main(){
    cout << std::fixed; cout << std::setprecision(1);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    if (n > 2)
    {
        MaxHeap max;
        MinHeap min;
        // base case 
        int smaller = a[0] < a[1]? a[0] : a[1];
        int larger = smaller == a[0]? a[1] : a[0];
        max.push(smaller); min.push(larger);
        int count = 1;
        for( int i = 1; i <= n ; ++i, ++count)
        {
            if (i == 1)
            {
                cout << static_cast<double>(a[0]) << endl;
            }
            else
            {   
                cout << ( count %2 ?  median(max, min) : median(max.top(), min.top()) ) << endl;
                if ( i < n)
                {
                     a[i] < max.top()? max.push(a[i]) : min.push(a[i]);
                        
                     if (abs(static_cast<int>(max.size()) - static_cast<int>(min.size() ) ) > 1)
                     {
                        if (max.size() > min.size())
                        { 
                            min.push(max.top());
                            max.pop();
                        }
                        else
                        {
                            max.push(min.top());
                            min.pop();
                        }
                     }     
                }
            }
        }
        
    }
    else
    {
        cout << static_cast<double>(a[0]) << endl;
    }
    return 0;
}

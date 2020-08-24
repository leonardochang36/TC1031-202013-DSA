#include <iostream>
#include <map>
#include "mytimer.h"
using namespace std;

// fib: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
// idx: 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10
int fibonacci(int n)
{
    if (n < 0)
        throw "illegal negative number";

    if (n < 2)
        return n;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

// memoized implementation
int fibonacci_v2(int n, map<int, int> &cache)
{
    if (n < 0)
        throw "illegal negative number";
    
    if (n < 2)
        return n;

    if (cache.find(n) != cache.end())
        return cache[n];

    int val = fibonacci_v2(n-1, cache) + fibonacci_v2(n-2, cache);
    cache[n] = val;
    return val;
}

int fibonacci_iter(int n)
{
    int a = 0, b = 1, fib = 0;
    for (int i = 0; i < n-1; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;    
}

int main()
{
    int ans, nth;
    cout << "Enter an index for the Fibonacci sequence: ";
    cin >> nth;
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    ans = fibonacci(nth);
    STOP_TIMING(t1);
    cout << ans << endl;
    SHOW_TIMING(t1, "Fibonacci version 1");


    map<int, int> cache;
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    int ans2 = fibonacci_v2(nth, cache);
    STOP_TIMING(t2);
    cout << ans2 << endl;
    SHOW_TIMING(t2, "Fibonacci version 2");

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    int ans3 = fibonacci_iter(nth);
    STOP_TIMING(t3);
    cout << ans3 << endl;
    SHOW_TIMING(t3, "Fibonacci version iter");

    return 0;
}
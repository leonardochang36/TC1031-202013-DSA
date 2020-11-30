#include <iostream>
using namespace std;

// n! = n * (n-1)!
int factorial(int n)
{
    if (n < 0)
        throw "illegal negative number";
    if (n == 0)
        return 1;

    return n * factorial(n-1);
}

int main()
{
    int ans;
    int number;
    cout << "Enter a number to compute factorial: ";
    cin >> number;
    ans = factorial(number);
    cout << "factorial is: " << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;

template <class T>
T GetMax(T a, T b)
{
    return (a > b ? a : b);
}

int main()
{

    int i = 13, j = 56;
    float k = 21.345, l = 54.1;
    int ri = GetMax(i, j);
    float rf = GetMax(k, l);
    cout << ri << endl;
    cout << rf << endl;

    return 0;
}



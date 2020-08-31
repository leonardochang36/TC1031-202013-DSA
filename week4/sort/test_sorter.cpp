#include <iostream>
#include <vector>
#include <stdlib.h>
#include "sorter.h"
#include "mytimer.h"

using namespace std;


template <typename T>
void print_vector(vector<T> arr, int N)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    // generate a random vector array of float
    vector<int> arr_f;
    int count = 10;
    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((int)rand() % 256);
        // arr_f.push_back((double)rand() / RAND_MAX);
    }

    cout << "Unsorted:" << endl;
    print_vector(arr_f, 10);

    // create instance of SelectionSort
    SelectionSort<int> selsort;
    selsort.sort(arr_f);

    cout << endl << "Sorted:" << endl;
    print_vector(arr_f, 10);

    return 0;
}

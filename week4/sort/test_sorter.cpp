#include <iostream>
#include <vector>
#include <stdlib.h>  // for std::rand
#include <algorithm> // for std::sort
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
    int count = 10000;
    cout << "ARRAY SIZE: " << count << endl;
    vector<float> arr_f;
    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((float)rand() / RAND_MAX);
    }
    vector<float> arr_s(arr_f);
    
    // create instance of SelectionSort
    DECLARE_TIMING(t);
    START_TIMING(t);
    SelectionSort<float> selsort;
    selsort.sort(arr_f);
    STOP_TIMING(t);
    SHOW_TIMING(t, "SelectionSort");

    // use std::sort
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    std::sort(arr_s.begin(), arr_s.end());
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "std::sort");

    // check if equal
    if (arr_f == arr_s)
        cout << "CONGRATS, your implementation is correct!" << endl;
    else
        cout << "Ops, sorry cowboy (cowgirl), it seems that something is still missing in your implementation" << endl;
    
    return 0;
}

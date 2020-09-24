#include <iostream>
#include <vector>
#include <stdlib.h>  // for std::rand
#include <algorithm> // for std::sort
#include "sorter.h"
#include "mytimer.h"

using namespace std;


template <typename T>
void print_vector(vector<T> arr, int N = 10)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

template <typename T>
void compare_vectors(vector<T> a, vector<T> b, string message = "")
{
    cout << endl << message << " ";
    // check if equal
    if (a == b)
        cout << "CONGRATS, your implementation is correct!" << endl;
    else
        cout << "Ops, sorry cowboy (cowgirl), it seems that something is still missing in your implementation" << endl;
}

template <typename T>
bool compare_lessthan(T &a, T &b)
{
    return a < b;
}


int main()
{
    int count;
    cout << "Enter array size: ";
    cin >> count;

    // generate a random vector array of float of size count
    vector<float> arr_f;
    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((float)rand() / RAND_MAX);
    }

    // create copies of original vector to be sorted
    vector<float> arr_1(arr_f);
    vector<float> arr_2(arr_f);
    vector<float> arr_3(arr_f);
    vector<float> arr_4(arr_f);
    vector<float> arr_5(arr_f);
    
    // get a baseline using std::sort
    DECLARE_TIMING(t);
    START_TIMING(t);
    std::sort(arr_f.begin(), arr_f.end());
    STOP_TIMING(t);
    SHOW_TIMING(t, "std::sort");

    // create instance of SelectionSort
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelectionSort<float> selsort;
    selsort.sort(arr_1, &compare_lessthan);
    STOP_TIMING(t1);
    compare_vectors(arr_f, arr_1, "Selection sort");
    SHOW_TIMING(t1, "SelectionSort:");

    // create instance of BubbleSort
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BubbleSort<float> bubsort;
    bubsort.sort(arr_2);
    STOP_TIMING(t2);
    compare_vectors(arr_f, arr_2, "Bubble sort:");
    SHOW_TIMING(t2, "BubbleSort");
    
    // create instance of InsertionSort
    DECLARE_TIMING(t3);
    START_TIMING(t3);
    InsertionSort<float> inssort;
    inssort.sort(arr_3);
    STOP_TIMING(t3);
    compare_vectors(arr_f, arr_3, "InsertionSort sort:");
    SHOW_TIMING(t3, "InsertionSort");

    // create instance of Merge
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort<float> mergesort;
    mergesort.sort(arr_4);
    STOP_TIMING(t4);
    compare_vectors(arr_f, arr_4, "Merge sort:");
    SHOW_TIMING(t4, "Merge sort");

    // create instance of Quicksort
    DECLARE_TIMING(t5);
    START_TIMING(t5);
    Quicksort<float> quicksort;
    quicksort.sort(arr_5, &compare_lessthan);
    STOP_TIMING(t5);
    compare_vectors(arr_f, arr_5, "Quicksort:");
    SHOW_TIMING(t5, "Quicksort");
        
    return 0;
}

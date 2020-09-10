#include <iostream>
#include <vector>
#include "rect.h"
#include "../week4/sort/sorter.h"

using namespace std;

bool compare_area(Rect &a, Rect &b)
{
    return a.area() > b.area();
}

bool compare_perimeter(Rect &a, Rect &b)
{
    return a.perimeter() < b.perimeter();
}

template <typename T>
bool compare_lessthan(T &a, T &b)
{
    return a < b;
}

int main()
{
    vector<Rect> rect_arr;
    rect_arr.push_back(Rect(2, 4));
    rect_arr.push_back(Rect(22, 42));
    rect_arr.push_back(Rect(4, 34));
    rect_arr.push_back(Rect(1, 2));
    rect_arr.push_back(Rect(5, 9));
    rect_arr.push_back(Rect(2, 7));

    SelectionSort<Rect> selsort;
    selsort.sort(rect_arr, &compare_perimeter);

    for (size_t i = 0; i < rect_arr.size(); i++)
        rect_arr[i].print();


    vector<float> arr_f;
    int count = 200;
    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((float)rand() / RAND_MAX);
    }

    SelectionSort<float> selsortf;
    selsortf.sort(arr_f, &compare_lessthan<float>);
    for (size_t i = 0; i < count; i++)
        cout << arr_f[i] << ", ";
    cout << endl;

    return 0;    
}


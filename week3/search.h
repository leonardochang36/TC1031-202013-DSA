#ifndef search_h
#define search_h

#include <stdlib.h>
#include <iostream>
#include <vector>

template <typename T>
class Search 
{
private:
    std::vector<T> arr;

public:
    Search();
    ~Search();

    void sort();
    void fill_random(int N);

    int search_sequential(T val);
};

#endif
#ifndef search_h
#define search_h

#include <stdlib.h>
#include <iostream>
#include <vector>

template <typename T>
class Search 
{
private:    

public:
    Search() {};
    ~Search() {};

    int search_sequential(std::vector<T> arr, T val, bool (*compare)(T &a, T &b))
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if ((*compare)(val, arr[i]))
                return i;
        }
        return -1;        
    };
};

#endif
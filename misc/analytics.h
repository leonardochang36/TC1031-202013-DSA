#ifndef _ANALYTICS_H
#define _ANALYTICS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include "dog.h"
#include "../week4/sort/sorter.h"

class Analytics
{
private:
    std::vector<Dog> data;

public:
    ~Analytics();
    Analytics();

    int load_data_from_csv(std::string path);
    void print_data();

    void sort_by_age();
};


#endif
#include "analytics.h"

using namespace std;

Analytics::~Analytics()
{}

Analytics::Analytics()
{}

int Analytics::load_data_from_csv(std::string path)
{
    ifstream file(path);
    if (!file.is_open())
        return -1;
    
    string line, race, age, name, sex;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, race, ',');
        getline(ss, age, ',');
        getline(ss, name, ',');
        getline(ss, sex, ',');

        Dog d(race, stoi(age), name, sex);
        data.push_back(d);
    }
    return 1;
}

void Analytics::print_data()
{
    for (size_t i = 0; i < data.size(); i++)
    {
        data[i].print();
    }    
}

void Analytics::sort_by_age()
{
    Quicksort<Dog> sorter;
    sorter.sort(data, &Dog::compare_age);
}
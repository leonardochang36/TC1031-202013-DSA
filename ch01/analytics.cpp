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
    
    string line, a1, a2, a3, a4, a5, a6, a7, a8;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, a1, ',');
        getline(ss, a2, ',');
        getline(ss, a3, ',');
        getline(ss, a4, ',');
        getline(ss, a5, ',');
        getline(ss, a6, ',');
        getline(ss, a7, ',');
        getline(ss, a8, ',');

        Log alog(a1, a2, a3, a4, a5, a6, a7, a8);
        data.push_back(alog);
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

int Analytics::length() 
{
    return data.size();
}

void Analytics::day_nth(int day_idx, std::string &date, int &count)
{
    date = "";
    count = 0;

    int curr = -1;
    for (size_t i = 0; i < data.size(); i++)
    {
        if (data[i].get_date() != date)
        {
            curr++;
            if (day_idx >= curr)
                date = data[i].get_date();
            else
                break;                
        }
        if (day_idx == curr)
            count++;
    }    
}

int Analytics::find_computer_owner(std::vector<std::string> names)
{
    Search<Log> my_search;
    for (size_t i = 0; i < names.size(); i++)
    {
        Log dummy_log;
        dummy_log.set_src_hostname(names[i]);
        int search_res = my_search.search_sequential(data, dummy_log, &Log::compare_src_hostname);
        if (search_res >= 0)
            return search_res;    
    }
    return -1;
}

std::vector<int> Analytics::dst_port_under_val(int threshold)
{
    vector<int> ports;
    Search<int> searcher;
    for (size_t i = 0; i < data.size(); i++)    
    {
        int dst_port = atoi(data[i].get_dst_port().c_str());
        if (dst_port < threshold)
        {
            if (searcher.search_sequential(ports, dst_port, &Log::compare_equal_than) < 0)
                ports.push_back(dst_port);
        }
    }
    return ports;    
}



#include "analytics.h"

using namespace std;

int main()
{
    Analytics my_analitic;
    
    ///////////////////////////////////////////////////////
    /// Load data
    ///////////////////////////////////////////////////////
    cout << "Loading data... ";
    if (my_analitic.load_data_from_csv("equipo0_.csv") > 0)
        cout << "DONE" << endl;
    else
    {
        cout << "ERROR loading input file... Exiting program...";
        return 0;
    }
    
    ///////////////////////////////////////////////////////
    /// QUESTION 1
    ///////////////////////////////////////////////////////
    cout << "Number of registers: " << my_analitic.length() << endl;

    ///////////////////////////////////////////////////////
    /// QUESTION 2
    ///////////////////////////////////////////////////////
    string date; int count;
    my_analitic.day_nth(1, date, count);
    cout << "Date of second day is: " << date << " with " << count << " logs." << endl;

    ///////////////////////////////////////////////////////
    /// QUESTION 3
    ///////////////////////////////////////////////////////
    std::vector<std::string> names;
    names.push_back("jeffrey");
    names.push_back("scott");
    names.push_back("katherine");
    cout << "Found register from ";
    for (size_t i = 0; i < names.size(); i++)
    {
        cout << names[i] << ", ";
    }
    cout << endl;
    cout << "\t" << (my_analitic.find_computer_owner(names) >= 0 ? "YES" : "NO") << endl;
    
    ///////////////////////////////////////////////////////
    /// QUESTION 7
    ///////////////////////////////////////////////////////
    cout << "Destination ports under 1000: \n\t";
    vector<int> ports = my_analitic.dst_port_under_val(1000);
    for (size_t i = 0; i < ports.size(); i++)
    {
        cout << ports[i] << ", ";
    }
    cout << endl;
    
    return 0;
}

#include "analytics.h"

int main()
{
    Analytics my_analitic;
    my_analitic.load_data_from_csv("file.csv");
    my_analitic.print_data();
    my_analitic.sort_by_age();
    std::cout << std::endl;
    my_analitic.print_data();

    return 0;
}
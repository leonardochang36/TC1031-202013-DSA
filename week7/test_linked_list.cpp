#include "linked_list.h"

using namespace std;

int main()
{    
    try
    {
        LinkedList<int> list;
        list.push(4);
        list.push(42);
        list.push(3);
        list.push(56);
        list.push(48);
        list.print();

        list.append(92);
        list.append(88);
        list.print();

        list.insert_item(66, 1);
        list.print();

        list.delete_item(1);
        list.print();

        for (size_t i = 0; i < list.length(); i++)
        {
            int item;
            list.get_nth(i, item);
            cout << item << ", ";
        }
        cout << endl;        
    }
    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    } 

    return 0;
}

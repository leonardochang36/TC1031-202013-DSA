#include "linked_list.h"

using namespace std;

int main()
{    
    // try
    // {
        LinkedList<int> list;
        list.push(3);
        list.push(42);
        list.push(4);
        list.push(56);
        list.push(43);
        list.print();

        list.append(88);
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

        cout << "The number of repetitions of 888 is " << list.count(888) << endl;

        list.delete_list();
        list.print();

        LinkedList<int> list2;
        list2.sorted_insert(12);
        list2.sorted_insert(32);
        list2.sorted_insert(3);
        list2.sorted_insert(457);
        list2.sorted_insert(32);
        list2.sorted_insert(12);
        list2.sorted_insert(8);
        list2.print();
        list2.remove_duplicates();
        list2.print();
        list2.reverse();
        list2.print();

    // }
    // catch(const char* e)
    // {
    //     std::cerr << "ERROR caught: " << e << std::endl;
    // } 

    return 0;
}

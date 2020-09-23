#include "linked_list.h"

int main()
{
    LinkedList<int> list;
    list.push(4);
    list.print();
    list.push(42);
    list.push(3);
    list.push(56);
    list.push(48);
    list.delete_item(0);    
    list.delete_item(0);    
    list.append(6);
    list.append(32);
    list.append(61);
    list.insert_item(100, 5);
    int item;
    list.get_nth(5, item);
    list.print();
    std::cout << item << std::endl;

    return 0;
}

#include "queue.h"

using namespace std;

int main()
{    
    try
    {
        Queue<int> list;
        list.enqueue(4);
        list.enqueue(42);
        list.enqueue(3);
        list.enqueue(56);
        list.enqueue(48);
        list.enqueue(2);
        list.print();

        cout << list.dequeue() << endl;    
        cout << list.dequeue() << endl;    
        cout << list.dequeue() << endl;    
        cout << list.dequeue() << endl;   
        list.print();
    }
    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    } 

    return 0;
}

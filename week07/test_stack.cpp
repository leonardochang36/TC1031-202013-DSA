#include "stack.h"

using namespace std;

int main()
{    
    try
    {
        Stack<int> list;
        list.push(4);
        list.push(42);
        list.push(3);
        list.push(56);
        list.push(48);
        list.push(2);
        list.print();

        cout << list.pop() << endl;    
        cout << list.pop() << endl;    
        cout << list.pop() << endl;    
        cout << list.pop() << endl;   
        list.print();
    }
    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    } 

    return 0;
}

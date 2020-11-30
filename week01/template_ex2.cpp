#include <iostream>
using namespace std;

// Clase Calculadora, que va a recibir 2 números y 
// devuelve la multiplicación, división, suma y resta.
// Usaremos templates

template <class T>
class Calculator
{
private:
    T a, b;

public:
    Calculator(T _a, T _b) {
        a = _a;
        b = _b;
    }

    T multiply() {return a *b;};
    T divide() {return a / b;};
    T add() {return a + b;};
    T substract() {return a - b;};

    void DisplayResult()
    {
        cout << "The numbers are: " << a << ", " << b << endl;
        cout << "Multiplication: " << multiply() << endl;
        cout << "Division: " << divide() << endl;
        cout << "Addition: " << add() << endl;
        cout << "Substraction: " << substract() << endl;
    }
};

int main()
{
    Calculator<int> calc_i(124, 345);
    Calculator<long> calc_d(1234.23, 346.346);
    cout << "Integer results:" << endl;
    calc_i.DisplayResult();

    cout << endl << "Double results:" << endl;
    calc_d.DisplayResult();

    return 0;
}

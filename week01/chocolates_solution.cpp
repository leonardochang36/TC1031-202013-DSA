// Given following three values, the task is to find the total number of maximum chocolates you can eat.
//     1. money : Money you have to buy chocolates
//     2. price : Price of a chocolate
//     3. wrap : Number of wrappers to be returned for getting one extra chocolate.
// It may be assumed that all given values are positive integers and greater than 1. 

// Examples:
// Input: money=16,price=2,wrap=2
// Output : 15
//      Price of a chocolate is 2. You can buy 8 chocolates from amount 16. You can return 8 wrappers back and get 4 more
//      chocolates. Then you can return 4 wrappers and get 2 more
//      chocolates. Finally you can return 2 wrappers to get 1
//      more chocolate.

// Input: money=15,price=1,wrap=3
// Output : 22
//      We buy and eat 15 chocolates
//      We return 15 wrappers and get 5 more chocolates. We return 3 wrappers, get 1 chocolate and eat it
//      (keep 2 wrappers). Now we have 3 wrappers. Return
//      3 and get 1 more chocolate.
//      So total chocolates = 15 + 5 + 1 + 1
//
// Input: money=20,price=3,wrap=5
// Output : 7


// Recursive C++ program to find maximum 
// number of chocolates 
#include <iostream> 
using namespace std; 
  
// Returns number of chocolates we can 
// have from given number of chocolates 
// and number of wrappers required to 
// get a chocolate. 
int countRec(int choc, int wrap) 
{ 
    // If number of chocolates is less than 
    // number of wrappers required. 
    if (choc < wrap) 
        return 0; 
  
    // We can immediatly get newChoc using 
    // wrappers of choc. 
    int newChoc = choc/wrap; 
  
    // Now we have "newChoc + choc%wrap" wrappers. 
    return newChoc + countRec(newChoc + choc%wrap, 
                              wrap); 
} 
  
// Returns maximum number of chocolates we can eat 
// with given money, price of chocolate and number 
// of wrappers required to get a chocolate. 
int countMaxChoco(int money, int price, int wrap) 
{ 
    // We can directly buy below number of chocolates 
    int choc = money/price; 
  
    // countRec returns number of chocolates we can 
    // have from given number of chocolates 
    return choc + countRec(choc, wrap); 
} 
  
// Driver code 
int main() 
{ 
    int money = 20; // total money 
    int price = 3;   // cost of each candy 
    int wrap = 5 ;   // number of wrappers needs to be 
                     // exchanged for one chocolate. 
  
    cout << countMaxChoco(money, price, wrap) << endl; 
    return 0; 
} 
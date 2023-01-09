/*
  Recursion Requirements:
    1. Base case
    2. Recursive case
    3. Each step shortens the problem
*/

#include <iostream>

using namespace std;

int factorial(int n)    {
    if (n ==1) return 1;
    return n * factorial(n-1);
}
 
int main() {

    cout << factorial(5);
    
}
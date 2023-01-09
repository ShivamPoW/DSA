/*
    Use breakpoint (line 28)
    Run Debug console
    Understand Call stack
*/ 

#include <iostream>

using namespace std;


void funcThree() {
    cout << "Good" << endl;
}

void funcTwo() {
    funcThree();
    cout << "Morning" << endl;
}

void funcOne() {
    funcTwo();
    cout << "World" << endl;
}


int main() {
    funcOne();
}
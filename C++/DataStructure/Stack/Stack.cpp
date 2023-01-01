#include <iostream>
#include <climits>
using namespace std;

class Node {
    public: 
        int value;
        Node* next;
    
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class Stack {
    private: 
        Node* top;
        int height;

    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop() {
            if(height == 0) return INT_MIN;
            
            Node* temp = top;
            int poppedValue = temp->value;
            top = temp->next;
            delete temp;
            height--;

            return poppedValue;
        }

        void printStack() {
            Node* temp = top;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop() {
            cout<< "Top: " << top->value << endl;
        }

        void getHeight() {
            cout<< "Height: " << height << endl;
        }

};

int main() {
    Stack* myStack = new Stack(4);
    myStack->push(5);
    myStack->push(7);
    myStack->push(1);
    myStack->pop();
    myStack->pop();

    myStack->printStack();
    myStack->getTop();
    myStack->getHeight();
    
}
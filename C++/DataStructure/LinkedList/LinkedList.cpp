#include <iostream>
using namespace std;

class Node {
    public: 
        int value;
        Node* next;

        Node (int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length = 0;

    public:
    //create new node
    LinkedList (int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList () {
        Node* temp = head;
        while(head) { 
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while(temp) {  // == (temp != nullptr)
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }

    // creates and adds new node to end
    void append (int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if(length == 0) return;
        Node* temp = head;
        Node* pre = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
            while (temp->next) {
            pre = temp;
            temp = temp->next ;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp; 
        length--;
    }

    // creates and add new node to beginning
    void prepend (int value) {
        Node* newNode = new Node(value);
        if (length == 0){
            head = newNode;
            tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if(length == 0) return;
        // This is required as temp needs to be deleted
        Node* temp = head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node* get(int index) {
        if(index < 0 || index >= length){ 
            return nullptr;
        }
        Node* temp = head;
        for(int i=0; i<index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if(temp){
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){
        if(index < 0 || index > length) return false;
        if(index == 0) {
            prepend(value);
            return true;
        };
        if(index == length){
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index-1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    } 

    void deleteNode(int index){
        if(index < 0 || index >= length) return;
        if(index == 0) return deleteFirst();
        if(index == length-1) return deleteLast();
        Node* prev = get(index-1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse( ){
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = temp->next;
        Node* before = nullptr;
        for(int i=0; i<length; i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }
 
    void getHead() {
        cout << "Head: " << head->value <<endl;
    }

    void getTail() {
        cout << "Head: " << tail->value <<endl;
    }

    void getLength() {
        cout << "Legnth: " << length <<endl;
    }
};


int main(){
    // LinkedList* myLinkedList = new LinkedList(1);
    // myLinkedList->append(2);
    // myLinkedList->append(3);
    // myLinkedList->printList();
    // myLinkedList->reverse();
    // cout << myLinkedList->get(2)->value << endl;
    // myLinkedList->set(1,33);
    // myLinkedList->prepend(1);
    // myLinkedList->printList();
}

// Hash Table (Seprate Chaining)

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        //  Take prime number
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public: 
        // Hash function
        int hash(string key) {
            int hash = 0;
            for (int i=0; i < key.length(); i++) {
                int asciivalue = int(key[i]);
                hash = (hash + asciivalue*23) % SIZE; //prime multiplication
            }
            return hash;
        }

        void set(string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if(!dataMap[index]) {
                dataMap[index] = newNode;
            }else {
                Node* temp = dataMap[index];
                while(temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(string key) {
            int index = hash(key);
            Node* temp = dataMap[index];
            while(temp) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return INT_MIN;
        }

        vector<string> keys() {
            vector<string> allkeys;
            for(int i=0; i < SIZE; i++) {
                Node* temp = dataMap[i];
                while(temp) {
                    allkeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allkeys;
        }

        void printTable() {
            for(int i=0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while(temp) {
                        cout << " {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }

        
};

int main() {
    HashTable* myHashTable = new HashTable();

    myHashTable->set("2G", 1);
    myHashTable->set("3G", 10);
    myHashTable->set("4G", 100);
    myHashTable->set("5G", 1000);
    myHashTable->set("6G", 10000);
    myHashTable->set("7G", 100000);

    myHashTable->printTable();

    cout << "8G: " << myHashTable->get("8G") << endl;
    cout << "5G: " << myHashTable->get("5G") << endl;
    cout << "7G: " << myHashTable->get("7G") << endl;

    vector<string> myKeys = myHashTable->keys();
    for(auto key : myKeys) {
        cout << key << " ";
    }
}
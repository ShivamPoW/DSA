// Breadth First Search (Line 68)
#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;
    
        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;

        // Can also initialize non empty root
        BinarySearchTree() {
            root = nullptr;
        }

        bool insert(int value){
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            };
            Node* temp = root;
            while(temp) { 
                if(newNode->value == temp->value) return false;
                if(newNode->value < temp->value){
                    if(!temp->left) {
                        temp->left = newNode; 
                        return true;
                    }
                    temp = temp->left;
                }
                 else {
                    if(!temp->right) {
                        temp->right = newNode; 
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value) {
            if(root == nullptr) return false;
            Node* temp = root;
            while (temp) {
                if(temp->value == value) return true;
                if(value < temp->value) {
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }
            return false;
        }

        void BFS() {
            queue<Node*> myQueue;
            myQueue.push(root);

            while (myQueue.size() > 0) {
                Node* currentNode = myQueue.front();
                myQueue.pop();
                cout << currentNode->value << " ";
                if (currentNode->left != nullptr) {
                    myQueue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    myQueue.push(currentNode->right);
            }
        }
}
};

int main() {
    BinarySearchTree* newBST = new BinarySearchTree();
    newBST->insert(5);
    newBST->insert(6);
    newBST->insert(3);
    newBST->insert(2);
    newBST->insert(4);

    newBST->BFS();
}

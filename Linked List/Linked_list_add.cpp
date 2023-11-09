#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void printData(Node *head);
void insertNode(Node *&head, Node *&tail, int data);

int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    int data;
    int operation;

    do{
    cout << "enter data: "; cin >> data;
    insertNode(head, tail, data);
    cout << "press 1 to add more"; cin >> operation;
    }while(operation == 1);
    printData(head);
}

void printData(Node *head){

    while(head != nullptr){
        cout << head->data << endl;
        head = head->next;
    }
}

void insertNode(Node *&head, Node *&tail, int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    tail->next = temp;
    tail = temp;
}

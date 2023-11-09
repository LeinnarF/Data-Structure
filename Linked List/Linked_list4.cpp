#include <iostream>
using namespace std;

class Node  //Create node
{
    public:
    int data;
    Node *next;
};

bool isEmpty(Node *head);
void insertFirstNode(Node *&head, Node *&tail, int data);
void insertNode(Node *&head, Node *&tail, int data);
void printData(Node *current);

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int data;
    int option,option2;

    do{
        cout << "enter number: "; cin >> data;
        insertNode(head,tail,data);
        cout << "Press 1 to input again: "; cin >> option;
    }while(option == 1);

    do{
        cout << "Press 1 to show data: "; cin >> option;
        if(option == 1){
            printData(head);
        }
        cout << "Press 1 for options: "; cin >> option2;
    }while(option2 == 2);
}

bool isEmpty(Node *head)
{
    if(head == nullptr) 
        return true;    
    else   
        return false;
}

void insertFirstNode(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node; //placeholder
    temp->data = data;
    temp->next = nullptr;

    head = temp;
    tail = temp;
}

void insertNode(Node *&head, Node *&tail, int data)
{
    if(isEmpty(head))
    {
        insertFirstNode(head,tail,data);
    }
    else
    {
        Node *temp = new Node;   //create a new node from a class node
        temp->data = data;
        temp->next = nullptr;

        tail->next = temp;
        tail = temp;
    }
}
void printData(Node *current)
{
    if(isEmpty(current)){
        cout << "Empty";
    }
    else{
        do{
            cout << "List" << endl;
            cout << current->next;
        }while(current != nullptr);
    }
}
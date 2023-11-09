#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

bool isEmpty(Node *head)
{
    if(head == nullptr)
        return true;
    else
        return false;
}

void insertFirstNode(Node *head, Node *tail, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    head = temp;
    tail = temp;
}

void insertNode(Node *&head, Node *&tail, int data )
{
    if(isEmpty(head))
    {
        insertFirstNode(head, tail, data);
    }
    else
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;

        tail->next = temp;
        tail = temp;
    }
}

void showData(Node *current)
{
    if(isEmpty(current)){
        cout << "Empty";
    }
    else{
        cout << "List" << endl;
        do{
            cout << current->data << endl;
            current = current->next;
        }while(current != nullptr);
    }

}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int data, option, option2;

    do{
        cout << "Enter number: "; cin >> data;
        insertNode(head, tail, data);
        cout << "Again? "; cin >> option;
    }while(option == 1);
    
    do{
        cout << "(1) show data \n(2)delete" << endl;cin >> option2;
        if(option2 == 1){
            showData(head);
        }
        else{
            cout << "invalid" << endl;
        }
        
    }while(option2 == 1);
    
    return 0;  
}


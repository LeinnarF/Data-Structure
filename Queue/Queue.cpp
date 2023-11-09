#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *first = nullptr;
Node *last = nullptr;

bool isEmpty()
{
    if(first == nullptr)
        return true;
    else
        return false;
}


void Enqueue(int value)
{
    if(isEmpty())
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        first = temp;
        last = temp;
    }
    else
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        last->next = temp;
        last = temp;
    }
}

void Dequeue()
{
    if(isEmpty())
        cout << "\nEmpty" << endl;
    else{
        Node *ptr = first;
        first = first->next;
        delete ptr;
    }
}

void viewFront()
{
    if(isEmpty())
        cout << "\nEmpty" << endl;
    else{
        cout << "\nFirst value: " << first->data << endl;
    }
}

void viewAll()
{
    if(isEmpty())
        cout << "\nEmpty" << endl;
    else
    {
        Node *temp = first;
        while(temp != nullptr){
            cout << temp->data;
            temp = temp->next;
            if(temp != nullptr)
                cout << " -> ";
        }
    }
}

int main()
{
    bool loop = true;

    while(loop){
        int choice;
        cout << "[1] Enqueue\n[2] Dequeue\n[3] View Front\n[4] View All\n[5] Exit" << endl;
        cout << "\n> " ;cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter value: ";
            cin >> value;
            Enqueue(value);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            viewFront();
            break;
        case 4:
            cout << "\nQueue: ";
            viewAll();
            cout << endl;
            break;
        case 5:
            cout << "Terminated.";
            loop = false;
            break;
        default:
            cout << "Invalid input!";
            break;
        }
        cout << "\n---------------------------\n\n";
    }
}
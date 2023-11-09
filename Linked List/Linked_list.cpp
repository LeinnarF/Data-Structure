#include <iostream>

using namespace std;

struct node
{
    int data;   // data
    node *next; // point to next
};

void printList(node *head);

int main()
{
    node *head = new node(); 
    node *tail = new node(); 

    head->data = 1;
    head->next = tail;
    tail->data = 2;
    tail->next = nullptr;

    cout << "List" << printList(head);

    return 0;
}

void printList(node *head)
{
    while(head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
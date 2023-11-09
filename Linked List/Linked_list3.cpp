#include <iostream>

using namespace std;

class Node
{
    public:
    int data;           //data
    Node *next;         //pointer to the next data
};

bool isEmpty(Node *head);
void insertFirstNode(Node *&head, Node *&last, int data);
void insertNode(Node *&head, Node *&last, int data);
void showData(Node *current);
void removeNode(Node *&head, Node *&last);

bool isEmpty(Node *head)
{
    if(head==nullptr)
        return true;
    else
        return false;
}

void insertFirstNode(Node *&head, Node *&last, int data)
{
    Node *temp= new Node;
    temp->data=data;
    temp->next=nullptr;

    head=temp;
    last=temp;
}
void insertNode(Node *&head, Node *&last, int data)
{
    if(isEmpty(head))
    {
        insertFirstNode(head, last, data);
    }
    else
    {
        Node *temp= new Node;
        temp->data=data;
        temp->next=nullptr;

        last->next=temp;
        last=temp;
    }
}

void showData(Node *current)
{
    if(isEmpty(current))
    {
        cout << "The list is already empty.";
    }
    else
    {   cout << "The list contains " << endl;
        do{

        cout << current->data << endl;
        current=current->next;
        }while(current!=nullptr);
    }
}
void removeNode(Node *&head, Node *&last)
{
    if(isEmpty(head))
    {
        cout << "The list is already empty. ";
    }
    else if (head==last)
    {
        delete head;
        head == nullptr;
        last == nullptr;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
}
int main()
{
    Node *head = nullptr;
    Node *last = nullptr;

    int data;
    int option,option2;
    do{
    cout << "Enter a number: ";
    cin >> data;
    insertNode(head, last, data);
    cout << "Press 1 to input more value: ";
    cin >> option;
    }while(option==1);

    do
    {
        cout << "Enter 1 to show data: " << endl;
        cout << "Enter 2 to remove data: "<< endl;
        cin >> option;
        if(option==1)
        {
            showData(head);
        }
        else if(option==2)
        {
            removeNode(head,last);
        }
        else
        {
            cout << "Invalid choice..";
        }
        cout << "Press 1 to show more options: ";
        cin >> option2;
    }while(option2==1);
    return 0;
}

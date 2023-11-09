#include <iostream>

using namespace std;

class Node
{
    public:
    int data;           //data
    Node *next;         //pointer to the next data
};

//declare functions
bool isEmpty(Node *head);
void insertFirstNode(Node *&head, Node *&last, int data);
void insertNode(Node *&head, Node *&last, int data);
void showData(Node *current);
void removeNode(Node *&head, Node *&last);
void deleteNode(Node *&head, Node *&last);//test
void changeHead(Node *&head);//test

//function instructions:
bool isEmpty(Node *head) //boolean function
{
    if(head==nullptr)
        return true; //returns true if there is no head item
    else
        return false; //returns false if there is head item
}

void insertFirstNode(Node *&head, Node *&last, int data) //inserting a first node(head)
{
    Node *temp= new Node; //new temporary item
    temp->data=data; //set temporary item data as data
    temp->next=nullptr; //set the temporary next item as null

    head=temp;
    last=temp;
}
void insertNode(Node *&head, Node *&last, int data) //insert a new node/item
{
    if(isEmpty(head)) //if head is not occupied
    {
        insertFirstNode(head, last, data);
    }
    else //if head is occupied
    {
        Node *temp= new Node; //create a new Node from class Node
        temp->data=data; //set temporary data as data
        temp->next=nullptr; //set the next temporary item as null

        last->next=temp; //set the last into next as temp
        last=temp;
    }
}

void showData(Node *current) //display the linked list
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
void removeNode(Node *&head, Node *&last) //remove an item from list
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

//warning: this is new block
void changeHead(Node *&head)
{
    if(isEmpty(head))
    {
        cout << "The list is already empty.";
    }
    else
    {
        int newData;
        cout << "Insert new data: ";
        cin >> newData;

        Node *temp=head;
        head=head->newData;
    }

}
//end of warning

//main function
int main() //main function
{
    Node *head = nullptr; //initialize head
    Node *last = nullptr; //initialize last

    int data; //declare data variable
    int option,option2; //declare choices

//from here(part1) - this do-while function enables the user to enter as many data as they want.
    do
   {
    cout << "Enter a number: ";
    cin >> data;
    insertNode(head, last, data);
    cout << "Press 1 to input more value: ";
    cin >> option;
    }while(option==1);
//to here(part1)
//from here(part2) - this do-while function lets the user choose what they want to do with the list.
    do
    {
        cout << "Enter 1 to show data: ";
        cout << "Enter 2 to remove data: ";
        cout << "Enter 3 to change the head node: ";
        cin >> option;
        if(option==1)
        {
            showData(head); //refer to the showData()instruction
        }
        else if(option==2)
        {
            removeNode(head,last); //refer to the removeNode() instruction
        }
        else if(option==3) //test choice
        {
            changeHead(head);
        }//end of test choice
        else
        {
            cout << "Invalid choice..";
        }
        cout << "Press 1 to show more options: ";
        cin >> option2;

    }while(option2==1); //loop for display, delete, or insert
//to here(part2)

    return 0;
}

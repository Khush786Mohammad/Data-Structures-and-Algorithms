#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void insertAtBeg(Node* &head, Node* &tail, int data);
void insertAtEnd(Node* &head, Node* &tail, int data);
void insertAtPos(Node* &head, Node* &tail, int data, int pos);
void deleteAtBeg(Node* &head, Node* &tail);
void deleteAtEnd(Node* &head, Node* &tail);
void deleteAtPos(Node* &head, Node* &tail, int pos);
void displayList(Node* &head, Node* &tail);

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice;
    int data;
    int pos;

    do
    {
        cout<<"1 to insert in the begining\n";
        cout<<"2 to insert in the end\n";
        cout<<"3 to insert in the given position\n";
        cout<<"4 to delete node at the begining\n";
        cout<<"5 to delete node at the last\n";
        cout<<"6 to delete given node\n";
        cout<<"7 to display the doubly ll\n";
        cout<<"8 to exit the terminal\n";

        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the node value\n";
                cin>>data;
                insertAtBeg(head,tail,data);
                break;

            case 2:
                cout<<"Enter the node value\n";
                cin>>data;
                insertAtEnd(head,tail,data);
                break;
            
            case 3:
                cout<<"Enter the node value\n";
                cin>>data;
                cout<<"Enter the position\n";
                cin>>pos;
                insertAtPos(head,tail,data,pos);
                break;

            case 4:
                deleteAtBeg(head,tail);
                break;

            case 5:
                deleteAtEnd(head,tail);
                break;
            
            case 6:
                cout<<"Enter the position to delete value\n";
                cin>>pos;
                deleteAtPos(head,tail,pos);
                break;
            
            case 7:
                displayList(head,tail);
                break;
            
            case 8:
                exit(1);

            default:
                cout<<"Wrong option selected\n";
        }
    } while (choice != 8);
    
    return 0;
}

void insertAtBeg(Node* &head, Node* &tail, int data)
{
    Node* node = new Node(data);
    if(head == nullptr)
    {
        head = node;
        tail = node;
        return;
    }

    else
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
    
}

void insertAtEnd(Node* &head, Node* &tail, int data)
{
    if(head == nullptr)
        return insertAtBeg(head,tail,data);
    
    else
    {
        Node* node = new Node(data);
        Node* temp = head;

        while(temp -> next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
    
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos)
{
    if(pos <= 0)
    {
        cout<<"Enter positive value\n";
        return;
    }
    if(head == nullptr || pos == 1)
        return insertAtBeg(head,tail,data);
    else
    {
        int count = 1;
        Node* node = new Node(data);
        Node* temp = head;
        Node* prev = nullptr;

        while(temp -> next != nullptr && count < pos)
        {
            count++;
            prev = temp;
            temp = temp->next;
        }

        if(count == pos)
        {
            prev->next = node;
            node->next = temp;
            node->prev = prev;
            temp->prev = node; 
        }
        else
        {
            temp->next = node;
            node->prev = temp;
        }
        
    }
    
}

void deleteAtBeg(Node* &head, Node* &tail)
{
    if(head == nullptr)
    {
        cout<<"List is empty\n";
        return;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        if(head != nullptr)
        {
            head->prev = nullptr;
        }
        delete(temp);
    }
    
}

void deleteAtEnd(Node* &head, Node* &tail)
{
    if(head == nullptr || head->next == nullptr)
    {
        return deleteAtBeg(head,tail);
    }
    else
    {
        Node* curr = head;
        Node* prev = nullptr;

        while(curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        curr->prev = nullptr;

        delete(curr);
    }
    
}

void deleteAtPos(Node* &head, Node* & tail, int pos)
{
    if(head == nullptr || pos == 1)
    {
        return deleteAtBeg(head,tail);
    }
    else
    {
        int count = 1;
        Node* curr = head;
        Node* prev = nullptr;

        while(curr->next != nullptr && count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(count == pos)
        {
            prev->next = curr->next;
            if(curr->next != nullptr)
                curr->next->prev = prev;

            delete(curr);
        }
    }
    
}

void displayList(Node* &head, Node* &tail)
{
    if(head == nullptr)
    {
        cout<<"List is empty\n";
        return; 
    }

    cout<<"\nDoubly Linked List is:\n";
    Node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"\n";

}
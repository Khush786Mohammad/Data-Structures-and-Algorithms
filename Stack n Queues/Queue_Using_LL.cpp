#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int main()
{
    int choice;
    Node* front = nullptr;
    Node* rear = nullptr;
    Node* node = nullptr;
    int size = 0;

    do
    {
        cout<<"---------------\t------------------\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Front Element\n";
        cout<<"4. Back Element\n";
        cout<<"5. Size of Queue\n";
        cout<<"6. Empty\n";

        cout<<"---------------\t------------------\n";

        cin>>choice;

        cout<<"---------------\t------------------\n";

        switch(choice)
        {
            case 1:
            int data;
            cin>>data;

            node = new Node(data);
            if(front == nullptr)
            {
                front = node;
                rear = node;
            }
            else
            {
                rear->next = node;
                rear = node;
            }
            size++;
            break;

            case 2:
            if(front == nullptr)
                cout<<"Queue is empty\n";
            else if(front == rear)
            {
                cout<<front->data<<" pop\n";
                delete front;
                front = nullptr;
                rear = nullptr;
            }
            else
            {
                cout<<front->data<<" pop\n";
                Node* temp = front;
                front = front->next;

                delete temp;
            }
            size--;
            break;

            case 3:
            if(front == nullptr)
                cout<<"Queue is empty\n";
            else
            {
                cout<<front->data<<"\n";
            }
            break;

            case 4:
            if(front == nullptr)
                cout<<"Queue is empty\n";
            else
            {
                cout<<rear->data<<"\n";
            }
            break;

            case 5:
            cout<<size<<endl;
            break;

            case 6:
            if(front == nullptr)
                cout<<"true\n";
            else
            {
                cout<<"false\n";
            }
            break;
            
            case 7:
            exit(1);

            default:
            cout<<"Wront Input\n";
            break;
        }
    } while (choice != 7);
    
    return 0;
}
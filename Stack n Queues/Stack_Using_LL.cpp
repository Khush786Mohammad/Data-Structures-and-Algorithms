#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void pushStack(Node* &top)
{
    int data;
    cin>>data;
        
    Node* newNode = new Node(data);
    
    if(top == nullptr)
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

int main()
{
    int choice;
    Node* top = nullptr;
    int size = 0;
    int data;
    
    do
    {
        cout<<"----------------\t--------------------\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Top\n";
        cout<<"4. empty\n";
        cout<<"5. size\n";
        
        
        cout<<"----------------\t--------------------\n";
        
        cin>>choice;
        cout<<"----------------\t--------------------\n";
        switch(choice)
        {
            case 1:
                pushStack(top);
                size++;
            break;
            
            case 2:
            
            if(top == nullptr)
            {
                cout<<"Stack is empty\n";
            }
            else
            {
                Node* temp = top;
                top = top->next;
                delete temp;
                size--;
            }
            break;
            
            case 3:
            if(top == nullptr)
            {
                cout<<"Stack is empty\n";
            }
            else
            {
                cout<<top->data<<endl;
            }
            break;
            
            case 4:
            if(top == nullptr)
                cout<<"true\n";
            else
                cout<<"false\n";
                
            break;
            case 5:
            cout<<size<<endl;
            break;
            
            case 6:
                exit(1);
            
            default:
            cout<<"Wrong input\n";
            
            
        }
        
    }while(choice != 6);
    return 0;
}
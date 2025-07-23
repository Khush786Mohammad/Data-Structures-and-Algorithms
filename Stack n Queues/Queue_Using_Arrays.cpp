#include<bits/stdc++.h>
using namespace std;
#define MAX 5

int main()
{
    int *queue = new int[MAX];
    int choice;
    int front = -1;
    int back = -1;

    do
    {
        cout<<"---------------\t------------------\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Front Element\n";
        cout<<"4. Back Element\n";
        cout<<"5. Size of Queue\n";
        cout<<"6. Empty\n";
        cin>>choice;

        cout<<"---------------\t------------------\n";

        switch(choice)
        {
            case 1:
            int data;
            cin>>data;
            if(back == MAX-1)
                cout<<"Queue is full\n";
            else if(front == -1)
            {
                front = front+1;
                back = back+1;

                queue[back] = data;
            }
            else
            {
                back = back+1;
                queue[back] = data;
            }
            
            break;

            case 2:
            if(front == -1)
                cout<<"Queue is Empty\n";
            else if(front == back)
            {
                queue[front] = -1;
                front = -1;
                back = -1;
            }
            else
            {
                queue[front] = -1;
                front = front+1;
            }
            break;

            case 3:
            if(front == -1)
                cout<<"Queue is empty\n";
            else
            {
                cout<<queue[front]<<"\n";
            }
            break;

            case 4:
            if(back == -1)
                cout<<"Queue is empty\n";
            else
            {
                cout<<queue[back]<<"\n";
            }
            break;

            case 5:
            if(front == -1)
                cout<<"0\n";
            else
            {
                cout<<back-front+1<<"\n";
            }
            break;

            case 6:
            if(front == -1)
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
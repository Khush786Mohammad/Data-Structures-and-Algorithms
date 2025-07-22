#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5];
    int top = -1;
    
    int choice;

    do
    {
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. top\n";
        cout<<"4. empty\n";
        cout<<"5. size\n";

        cin>>choice;

        switch (choice)
        {
        case 1:
            int data;
            cin>>data;

            if(top == 4)
                cout<<"Stack is full!!\n";
            else
            {
                top = top+1;
                arr[top] = data;
            }
            
            break;
        
        case 2:
            if(top == -1)
            {
                cout<<"Stack is empty\n";
            }
            else
            {
                cout<<arr[top]<<" pop from the stack\n";
                arr[top] = -1;
                top = top-1;
            }
            break;

        case 3:
            if(top == -1)
            {
                cout<<"Stack is empty\n";
            }
            else
            {
                cout<<"Top: "<<arr[top]<<"\n";
            }
            break;
        
        case 4:
            if(top == -1)
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
            break;

        case 5:
            cout<<"Size is: "<<top+1<<endl;
        
        break;
        
        case 6:
            exit(1) ;
        default:
            break;
        }
    } while (choice != 6);
    
    return 0;
}
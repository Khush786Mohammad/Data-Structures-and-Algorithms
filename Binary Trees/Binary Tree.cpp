#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree(node* root)
{
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    if(data == -1)
    return NULL;
    root = new node(data);
    

    cout<<"Enter the data to insert in left of "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Enter the data to insert in right of "<<data<<endl;
    root->right = createTree(root->right);
    return root;
}

void LevelOrderTraversal(node *root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<"\n";

            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);
            
            if(temp->right)
            q.push(temp->right);
        }
    }
}

void inorder(node *root)
{
    
    if(root == NULL)
    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node *root)
{
    if(root == nullptr)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(root == nullptr)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void buildLevelOrder(node* &root)
{
    queue<node *> q;
    
    int data;
    cout<<"Enter the root node:\n";
    cin>>data;

    root = new node(data);

    q.push(root);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout<<"Enter the data to the left of "<<temp->data<<endl;
        cin>>data;
        if(data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout<<"Enter the data to the right of "<<temp->data<<"\n";
        cin>>data;
        if(data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    
}

void morrisTraversal(node* root)
{
    if(root == NULL)
    return ;

    node *curr , *predecessor;
    curr = root;

    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            predecessor = curr->left;
            while(predecessor->right != NULL && predecessor->right != curr)
            predecessor = predecessor->right;

            if(predecessor->right == NULL)
            {
                predecessor->right=curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }

}
int main()
{
    node *root = NULL;
    //create a tree

    //root = createTree(root);
    buildLevelOrder(root);

    


    // LevelOrderTraversal(root);
    // cout<<endl;
    //  1 2 3 4 -1 -1 -1 5 -1 -1 6 7 -1 -1 8 -1 -1

    inorder(root);
    // cout<<"\n";
    // preorder(root);
    // cout<<"\n";
    // postorder(root);
    cout<<"\n";
    morrisTraversal(root);
    return 0;
}
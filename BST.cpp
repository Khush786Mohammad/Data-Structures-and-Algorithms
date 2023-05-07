#include<iostream>
#include<queue>
#include<map>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *CreateBST(node* root , int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = CreateBST(root->right , data);
    }
    else
    {
        root->left = CreateBST(root->left , data);
    }
    return root;
}

void takeInput(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = CreateBST(root , data);
        cin>>data;
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void leveOrderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<frontNode->data<<" ";
            if(frontNode->left)
        {
            q.push(frontNode->left);
        }
            if(frontNode->right)
        {
            q.push(frontNode->right);
        }
        }
        
    }
}

int minValue(node* root)
{
    if(root == nullptr)
    return -1;

    node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxValue(node* root)
{
    if(root == NULL)
    return -1;


    node *temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

void Node_To_Parent(node* root , map<node*,node*> &mp)
{
    queue<node*> q;
    q.push(root);

    mp[root] = NULL;

    while(!q.empty())
    {
        node* frontNode = q.front();
        q.pop();

        if(frontNode->left)
        {
            q.push(frontNode->left);
            mp[frontNode->left] = frontNode;
        }
        if(frontNode->right)
        {
            q.push(frontNode->right);
            mp[frontNode->right] = frontNode;
        }
    }
} 

int successor(node* root , node* temp , map<node*,node*> &mp)
{
    if(temp->right != NULL)
    {
        return minValue(temp->right);
    }

    node* p = mp[temp];

    while(p != NULL && p->right ==temp)
    {
        temp = p;
        p = mp[temp];
    }
    if(p==NULL)
    return -1;
    return p->data;
}

int predecessor(node* root , node* temp , map<node*,node*> &mp)
{
    if(temp->left != NULL)
    {
        return maxValue(temp->left);
    }

    node* parent = mp[temp];

    while(parent != NULL && parent->left == temp)
    {
        temp = parent;
        parent = mp[parent];
    }
    if(parent == NULL)
    return -1;
    return parent->data;
}

int main()
{
    node *root = NULL;
    cout<<"Enter the data\n";
    takeInput(root);

    inorder(root);
    cout<<endl;

    preorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

    leveOrderTraversal(root);
    cout<<endl;

    int min = minValue(root);
    cout<<"Minimum Value in BST is : "<<min<<endl;
    int max = maxValue(root);

    cout<<"Maximum Value in BST is : "<<max<<endl;

    //create Mapping of node to its parent
    map<node*,node*> mp;
    Node_To_Parent(root,mp);

    node* temp = root->right;
    cout<<"successor of "<<temp->data<<endl;
    cout<<successor(root , temp , mp);
    cout<<endl;

    cout<<"Predecessor of "<<temp->data<<endl;
    cout<<predecessor(root,temp,mp);
    cout<<endl;
    return 0;
}
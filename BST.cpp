#include<iostream>
#include<queue>
#include<map>
using namespace std;

// Class Node Declaration
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

int minValue(node*);
int maxValue(node*);

// Create BST
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

//Delete from BST
node* deleteFromBST(node* root , int val)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data == val)
    {
        // 0 - child
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 - child
        if(root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        
        if(root->right != NULL && root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2- child
        if(root->left != NULL && root->right != NULL)
        {
            //Either find and replace the minimum value node from right sub-tree
            int mini = minValue(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
            return root;

            //or find and replace the maximum value node from left sub-tree
            /*int maxi = maxValue(root->left);
            root->data = maxi;
            root->left = deleteFromBST(root->left , maxi);
            return root;
            */
        }

    }
    else if(root -> data > val)
    {
        root->left = deleteFromBST(root->left , val);
    }
    else
    {
        root->right = deleteFromBST(root->right , val);
    }
    return root;
}

// Inorder Traversal LNR 
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

// PreOrder Traversal NLR
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

// PostOrder Traversal LRN
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
// Level Order Traversal
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
        node* frontnode = q.front();
        q.pop();

        if(frontnode == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<frontnode->data<<" ";
            if(frontnode->left)
        {
            q.push(frontnode->left);
        }
            if(frontnode->right)
        {
            q.push(frontnode->right);
        }
        }
        
    }
}

// Minimum Value in BST
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

// Maximum Value in BST
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

// Create Mapping of Node to its parent
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

// Inorder Successor
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

// Inorder Predecessor
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

// Main Function
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

    node* temp = root->left->left->right;
    cout<<"successor of "<<temp->data<<endl;
    int succ = successor(root , temp , mp);
    if(succ == -1)
    cout<<"NULL\n";
    else
    cout<<succ;
    cout<<endl;

    cout<<"Predecessor of "<<temp->data<<endl;
    int pre = predecessor(root,temp,mp);
    if(pre == -1)
    cout<<"NULL\n";
    else
    cout<<pre;
    cout<<endl;

    // Deletion Part

    root = deleteFromBST(root,20);

    inorder(root);
    cout<<endl;

    preorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

    leveOrderTraversal(root);
    cout<<endl;

    min = minValue(root);
    cout<<"Minimum Value in BST is : "<<min<<endl;
    max = maxValue(root);

    cout<<"Maximum Value in BST is : "<<max<<endl;

   
    temp = root->left->left->right;
    cout<<"successor of "<<temp->data<<endl;
    succ = successor(root , temp , mp);
    if(succ == -1)
    cout<<"NULL\n";
    else
    cout<<succ;
    cout<<endl;

    cout<<"Predecessor of "<<temp->data<<endl;
    pre = predecessor(root,temp,mp);
    if(pre == -1)
    cout<<"NULL\n";
    else
    cout<<pre;
    cout<<endl;


    return 0;
}
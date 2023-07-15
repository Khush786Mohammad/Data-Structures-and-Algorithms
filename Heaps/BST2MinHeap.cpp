#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

    node *BuildBST(int val , node* &root)
    {
        if(root == NULL)
        {
            root = new node(val);
            return root;
        }
        if(val > root->data)
        {
            root->right = BuildBST(val,root->right);
        }
        else
        {
            root->left = BuildBST(val,root->left);
        }
        return root;
    }
    void takeInput(node* &root)
    {
        int data;
        cout<<"Enter the data\n";
        cin>>data;

        while(data != -1)
        {
            root = BuildBST(data , root);
            cin>>data;
        }
    }

    void inorder(vector<int> &v , node* root)
    {
        if(root == NULL)
        return ;

        inorder(v,root->left);
        v.push_back(root->data);
        inorder(v,root->right);
    }

    void toMinHeap(vector<int> &v , int &i , node* root)
    {
        if(root == NULL)
        return ;

        root->data = v[i];
        i = i+1;
        toMinHeap(v,i,root->left);
        toMinHeap(v,i,root->right);
    }

int main()
{
    node *tree = NULL;
    takeInput(tree);
    vector<int> v;
    inorder(v,tree);

    for(auto it : v)
    cout<<it<<" ";cout<<endl;
    int index = 0;

    toMinHeap(v,index,tree);
    v.clear();
    inorder(v,tree);
    for(auto it : v)
    cout<<it<<" ";cout<<endl;
    return 0;
}
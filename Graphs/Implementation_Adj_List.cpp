#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class graph
{
    public:
    unordered_map<int,list<int>> adj;

    void addEdgeDirected(int u , int v)
    {
        adj[u].push_back(v);
    }

    void addEdgeUndirected(int u , int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printadjList()
    {
        cout<<"\n-----Adjaceny List-----\n";
        for(auto i : adj)
        {
            cout<<i.first<<"->";
            for(auto j : i.second)
            {
                cout<<j<<"  ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g;

    int n, m;
    cout<<"Enter the number of vertex\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;

    int direction;

    cout<<"Enter 1 For Directed Graph else 0 for Undirected Graph\n";
    cin>>direction;

    for(int i = 1 ; i<=m ; i++)
    {
        int u,v;
        cin>>u>>v;

        if(direction == 1)
        g.addEdgeDirected(u,v);

        else
        g.addEdgeUndirected(u,v);

    }

    g.printadjList();


    return 0;
}
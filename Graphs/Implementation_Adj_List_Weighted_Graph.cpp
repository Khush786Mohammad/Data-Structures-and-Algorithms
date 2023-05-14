#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{
    public:

    unordered_map<int , list< pair<int,int>> > adj; //pair first-> connected node and pair->second == weight

    void addEdgeDirected(int u , int v , int weight)
    {
        adj[u].push_back({v,weight});
    }

    void addEdgeUndirected(int u , int v , int weight)
    {
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    void printAdjList()
    {
        for(auto i : adj)
        {
            cout<<i.first<<" ---> ";
            for(auto j : i.second)
            {
                cout<<"("<<j.first<<" "<<j.second<<")"<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int dir , n , m;
    
    cout<<"Enter 1 for Directed Graph or 0 for Undirected Graph\n";
    cin>>dir;

    cout<<"Enter the number of Nodes\n";
    cin>>n;

    cout<<"Enter the number of edges\n";
    cin>>m;

    graph g;

    cout<<"Enter the connected nodes along with their weights\n";

    for(int i = 1 ; i<=m ; i++)
    {
        int u , v , wei;
        cin>> u >> v >> wei;

        if(dir == 1)
        {
            g.addEdgeDirected(u,v,wei);
        }
        else
        {
            g.addEdgeUndirected(u,v,wei);
        }
    }

    g.printAdjList();
    return 0;
}
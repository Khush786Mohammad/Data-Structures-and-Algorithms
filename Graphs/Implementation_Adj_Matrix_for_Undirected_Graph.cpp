// Graph Implementation By Adjacency Matrix for Undirected Graph

#include<iostream>
using namespace std;

int main()
{
    int n , m; // n--> nodes    m--> edges
    cin>>n>>m;

    int adj[n+1][m+1] = {0};

    for(int i = 1 ; i<=m ; i++)
    {
        int u , v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1; // comment this line for directed graph
    }

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1; j<=n ; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
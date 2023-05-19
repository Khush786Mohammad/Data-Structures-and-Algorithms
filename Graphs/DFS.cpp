#include<bits/stdc++.h>
using namespace std;

void dfs(int node , unordered_map<int,bool> &visited , unordered_map<int,list<int>> &adj , vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = 1;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,ans);
        }
    }


}

int main()
{
     int n , m;
    cout<<"Enter the number of nodes\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>m;

    unordered_map<int,list<int>> adj;

    for(int i = 1 ; i<=m ; i++)
    {
        int u , v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto itr : adj)
    {
        cout<<itr.first<<"-->";
        for(auto ptr : itr.second)
        {
            cout<<ptr<<" ";
        }
        cout<<endl;
    }

    unordered_map<int,bool> visited;
    vector<int> ans;
    for(int i = 1 ; i<=n ; i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,ans);
        }
    }

    cout<<"---------------------BFS Traversal Of Graph---------------------\n";

    for(auto &a : ans)
    cout<<a<<"  ";
    return 0;
}
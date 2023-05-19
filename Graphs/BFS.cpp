#include<bits/stdc++.h>
using namespace std;

void BFS(unordered_map<int,bool> &visited , unordered_map<int,list<int>> &adj , vector<int> &ans , int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i : adj[frontNode])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
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
            BFS(visited,adj,ans,i);
        }
    }

    cout<<"---------------------BFS Traversal Of Graph---------------------\n";
    for(auto &a : ans)
    {
        cout<<a<<"  ";
    }
    return 0;
}
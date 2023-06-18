#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    vector<int> rank , parent;

public:
      DisjointSet(int n)
      {
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i = 0 ; i<=n ; i++)
        {
            parent[i] = i;
        }
      }

      int findUlParent(int node)
      {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findUlParent(parent[node]);
      }

      void unionByRank(int u , int v)
      {
        int ul_pu = findUlParent(u);
        int ul_pv = findUlParent(v);

        if(ul_pu == ul_pv)
        return;

        if(rank[ul_pu] < rank[ul_pv]){
            parent[ul_pu] = ul_pv;
        }
        else if(rank[ul_pu] > rank[ul_pv])
        {
            parent[ul_pv] = ul_pu;
        }
        else{
            parent[ul_pu] = ul_pv;
            rank[ul_pv]++; 
        }
    }

};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUlParent(3) == ds.findUlParent(7))
    {
        cout<<"Same Components\n";
    }
    else{
        cout<<"Different Components\n";
    }
    ds.unionByRank(3,7);
    if(ds.findUlParent(3) == ds.findUlParent(7))
    {
        cout<<"Same Components\n";
    }
    else{
        cout<<"Different Components\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    vector<int> size , parent;

public:
      DisjointSet(int n)
      {
        size.resize(n+1,1);
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

      void unionBySize(int u , int v)
      {
        int ul_pu = findUlParent(u);
        int ul_pv = findUlParent(v);

        if(ul_pu == ul_pv)
        return;

        if(size[ul_pu] < size[ul_pv]){
            parent[ul_pu] = parent[ul_pv];
            size[ul_pv] += size[ul_pu];
        }
        else{
            parent[ul_pv] = parent[ul_pu];
            size[ul_pu] += size[ul_pv];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    if(ds.findUlParent(2) == ds.findUlParent(3))
    {
        cout<<"Same Components\n";
    }
    else{
        cout<<"Different Components\n";
    }
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUlParent(1) == ds.findUlParent(7))
    {
        cout<<"Same Components\n";
    }
    else{
        cout<<"Different Components\n";
    }
    ds.unionBySize(3,7);
    if(ds.findUlParent(1) == ds.findUlParent(7))
    {
        cout<<"Same Components\n";
    }
    else{
        cout<<"Different Components\n";
    }
    
    return 0;
}
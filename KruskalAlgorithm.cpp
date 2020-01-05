#include<bits/stdc++.h>
#define size 100
using namespace std;

class Node
{
public:
    int source;
    int destination;
    int weight;
};

Node n[size];
Node mst[size];
int p[size];
bool compare(Node u,Node v)
{
    return u.weight < v.weight;
}
int Set(int parent)
{
    return (p[parent]==parent) ? parent : Set(p[parent]);
}

void KruskalAlgo(int v, int e)
{
    int c = 0, c1 = 0, total_weight = 0;
    for(int i = 1; i <= v; i++)
    {
        p[i] = i;
    }

    for(int i = 1; i <= e; i++)
    {
        int s,d,set_u,set_v;
        s = n[i].source;
        d = n[i].destination;
        set_u = Set(s);
        set_v = Set(d);

        if(set_u != set_v && c <v-1)
        {
            mst[c1] = n[i];
            c++;
            c1++;
            p[s] = v;
        }
    }

    for(int i=1 ; i <= c1; i++)
    {
        cout<<mst[i].source<<" ";
        cout<<mst[i].destination<<" ";
        cout<<mst[i].weight<<" ";
        cout<<endl;

        total_weight = total_weight + mst[i].weight;
    }
    cout<<"Total Minimum Spanning Tree Cost  = "<<total_weight<<endl;
}


int main()
{
    freopen("in.txt","r",stdin);
    int vertex;
    int edge;
    int u,v,w;
    cin>>vertex>>edge;

    for(int i = 1; i <= edge; i++)
    {
        cin>>u>>v>>w;
        n[i].source = u;
        n[i].destination = v;
        n[i].weight = w;
    }

    for(int i = 1; i <= edge; i++)
    {
        cout<<n[i].source<<" ";
        cout<<n[i].destination<<" ";
        cout<<n[i].weight<<" ";
        cout<<endl;
    }

    cout<<endl<<"After Sorting :"<<endl;

    sort(n,n+edge+1,compare);

    for(int i = 1; i <= edge; i++)
    {
        cout<<n[i].source<<" ";
        cout<<n[i].destination<<" ";
        cout<<n[i].weight<<" ";
        cout<<endl;
    }

    cout<<endl<<"Minimum Spanning Tree : "<<endl;

    KruskalAlgo(vertex,edge);

    return 0;
}


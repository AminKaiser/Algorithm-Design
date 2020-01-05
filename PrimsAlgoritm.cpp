#include<bits/stdc++.h>
#define size 100
using namespace std;

int adj[size][size];
int key[size];
int p[size];
bool color[size];
int WHITE = 0;
int BLACK = 1;

class Node
{
public:
    int ver,weight;
    Node(int vr,int c)
    {
        ver = vr;
        weight = c;
    }
};

bool operator<(Node u, Node v)
{
    return u.weight > v.weight;
}

void Prims(int v,int u)
{
    int c = 0;
    for(int i=1; i<= v; i++)
    {
        key[i] = INT_MAX;
        color[i] = WHITE;
    }


    key[u] = 0;
    p[u] = NULL;

    priority_queue<Node>q;
    q.push(Node(u,0));

    while(!q.empty())
    {
        Node t = q.top();
        q.pop();


        for(int i = 1; i <= v; i++)
        {
            if(adj[t.ver][i]!=0)
            {
                if(color[i]==WHITE && adj[t.ver][i]<key[i])
                {
                    key[i] = adj[t.ver][i];
                    p[i] = t.ver;
                    q.push(Node(i,key[i]));
                }
                color[t.ver] = BLACK;
            }
        }
    }



    for(int i = 2;i <= v; i++)
    {
        cout<<p[i]<<" "<<i<<" "<<adj[i][p[i]]<<endl;
        c = c + adj[i][p[i]];
    }
    cout<<"Minimum Cost = "<<c<<endl;
}


int main()
{
    freopen("in.txt","r",stdin);
    int vertex,edge;
    cin>>vertex>>edge;
    for(int i=1; i <= edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    Prims(vertex,1);
    return 0;
}

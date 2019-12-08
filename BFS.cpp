#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define size 100

int adj[size][size], color[size],d[size], parent[size];
int vertex,edge;

void BFS(int s){

    for(int u=0; u<=vertex; u++)
    {
        color[u]  = WHITE;
        d[u]    = INT_MAX;
        parent[u] = -1;
    }
    d[s]= 0;
    parent[s] = -1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u;
        u = q.front();
        color[u] = GRAY;
        q.pop();
        cout<<u<<" ";

        for(int v=0;v<vertex;v++)
        {
            if(adj[u][v] == 1)
            {
                if(color[v] == WHITE)
                {
                    q.push(v);
                    d[v] = d[u] + 1;
                    parent[v] = u;
                }
            }
        }
    }
}

int main(){
    freopen("bfsin.txt","r",stdin);
    cin>>vertex>>edge;
    int v1,v2;
    for(int i=0; i<edge; i++){
        cin>>v1>>v2;
        adj[v1][v2] = 1;
    }
    BFS(0);
    cout<<endl;
    cout<<parent[2]<<endl;
    cout<<d[5];
    return 0;
}

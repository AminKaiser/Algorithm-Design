#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define size 30

int adj[size][size], color[size],d[size], f[size],prev[size];
int Time, vertex, edge;

stack <int> tps;

void DFS_Visit(int u){

    color[u] = GRAY;
    Time = Time + 1;
    d[u] = Time;

    for(int v = 0; v < vertex; v++){

        if(adj[u][v] == 1){
            if(color[v] == WHITE){
                prev[v] = u;
                DFS_Visit(v);
            }
        }
    }
    color[u] = BLACK;
    Time = Time + 1;
    f[u] = Time;
    tps.push(u);
}

void DFS(){
    for(int u=0; u<vertex; u++){
        color[u] = WHITE;
        prev[u]=-1;
        d[u] = INT_MAX;
        f[u] = INT_MAX;
    }

    for(int u=0; u<vertex; u++){
        if(color[u] == WHITE){
            DFS_Visit(u);
        }
    }
}

void DFS_Display()
{
    for(int i=0; i < vertex; i++){
        cout<<"Vertex :"<<(char)('A' + i);

        if(prev[i] == -1)
            cout<<" Previous Vertex -> null";

        else
            cout<<"  Previous->"<<(char)('A' + prev[i]);
        cout<<"  Discovery Time ->"<<d[i]<<"  Finishing Time ->"<<f[i]<<endl;
    }
}

void Topological_Display()
{
    cout<<endl<<"Topological Sort : "<<endl;
    while(!tps.empty())
    {
        cout<<char(tps.top() + 'A') <<" ";
        tps.pop();
    }
    cout<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    cin>>vertex>>edge;

    int v1,v2;
    for(int i=0; i < edge; i++){
        cin>>v1>>v2;
        adj[v1][v2] = 1;
    }
    DFS();

    DFS_Display();

    Topological_Display();

    return 0;
}

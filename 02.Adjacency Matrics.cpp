#include<bits/stdc++.h>
using namespace std;

int adj[100][100];

class graph{
public:
    int edge,vertex;

    void input()
    {
        cin>>edge>>vertex;
        for(int i=0;i<edge;i++) /// edge connection
        {
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
        }
    }

    void Output()
    {
        for(int i=1;i<=vertex;i++)
        {
            for(int j=1;j<=vertex;j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};



int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    graph obj;
    obj.input();
    obj.Output();

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int adj[25][25];
int path[7];
int d[15];
int cost[15];
vector<int>vec[25];

void FGragh(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(adj[i][j]!=0)
            {
                vec[i].push_back(j);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        int sz = vec[i].size();
        cout<<i<<"--> ";
        for(int j=0;j<sz;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    cost[n] = 0;
    d[n]=n;
    for(int j=n-1;j>=1;j--)
    {
        int mn,des_ver,min_des,sz = vec[j].size();
        mn = INT_MAX;
        for(int i=0;i<sz;i++)
        {
            des_ver = vec[j][i];
            if(mn>adj[j][des_ver]+cost[des_ver])
            {
                min_des = des_ver;
                mn = adj[j][des_ver]+cost[des_ver];
            }
        }
        cost[j] = mn;
        d[j] =min_des;
    }
    path[1] = 1;
    path[k] = n;
    for(int j=2;j<k;j++)
        path[j] = d[path[j-1]];
    for(int i=1;i<=k;i++)
        cout<<path[i]<<" ";
    cout<<endl;
    cout<<"Total Shortest Distance = "<<cost[1]<<endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    int vertex,edge,k;
    cin>>edge>>vertex>>k;
    for(int i=0;i<edge;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u][v]=cost;
    }
//    for(int i=1;i<=vertex;i++)
//    {
//        for(int j=1;j<=vertex;j++)
//        {
//            cout<<adj[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    FGragh(k,vertex);
    return 0;
}

/**

edge=21, vertex=12, stage=5
21 12 5
1 2 8
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
12 9 4
7 10 5
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5

**/

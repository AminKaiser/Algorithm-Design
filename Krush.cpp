#include<bits/stdc++.h>
using namespace std;

class edge{
public:
    int s,d,w;
    Edge(int ss,int dd,int ww)
    {
        s = ss;
        d = dd;
        w = ww;
    }
};

bool compare(edge a,edge b)
{
    return a.w<b.w;
}

edge obj[100];
edge MST[100];
edge bad[100];

int parent[100];

int Find_Set(int r)
{
    return (parent[r]==r) ? r : Find_Set(parent[r]);
}

void Kruskal(int ed,int ver)
{
    for(int i=1;i<=ver;i++)
    {
        parent[i] = i;
    }
    int cnt=0,l=0,m=0;
    for(int i=0;i<ed;i++)
    {
        int u,v,j,k;
        u = obj[i].s;
        v = obj[i].d;
        j = Find_Set(u);
        k = Find_Set(v);

        if(j!=k && cnt<ver-1) //
        {
            MST[l] = obj[i];
            cnt++;
            l++;
            parent[u]=v;
        }
//        else
//        {
//            bad[m] = obj[i];
//            m++;
//        }
    }
    int total_cost = 0;
    for(int i=0;i<l;i++)
    {
        cout<<MST[i].s<<" ";
        cout<<MST[i].d<<" ";
        cout<<MST[i].w<<endl;
        total_cost +=MST[i].w;
    }
    cout<<"Total Minimum Cost = "<<total_cost<<endl;
    /// baad array print
//    for(int i=0;i<m;i++)
//    {
//        cout<<bad[i].s<<" ";
//        cout<<bad[i].d<<" ";
//        cout<<bad[i].w<<endl;
//    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int ed,ver;
    cin>>ver>>ed;
    for(int i=0;i<ed;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        obj[i].Edge(u,v,cost);
    }
    sort(obj,obj+ed,compare);
    for(int i=0;i<ed;i++)
    {
        cout<<obj[i].s<<" ";
        cout<<obj[i].d<<" ";
        cout<<obj[i].w<<endl;
    }
    cout<<"MST Display"<<endl;
    Kruskal(ed,ver);
    return 0;
}

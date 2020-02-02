#include<bits/stdc++.h>
using namespace std;

int N,M;

void Display(int k,int weight[],int x[])
{
    for(int i=0;i<=k;i++)
        if(x[i])
            cout<<weight[i]<<" ";
    cout<<endl;
}

void SumofSubSet(int s,int r,int k,int weight[],int x[])
{
    x[k]=1;
    if(k<N && s+weight[k]==M)
        Display(k,weight,x);
    if(k<N)
        SumofSubSet(s+weight[k],r-weight[k],k+1,weight,x);
    if(k<N)
    {
        x[k]=0;
        SumofSubSet(s,r-weight[k],k+1,weight,x);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int sum=0,weight[100],x[100];
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>weight[i];
        sum+=weight[i];
    }
    cout<<"Total Input Sum = "<<sum<<endl;
    SumofSubSet(0,sum,0,weight,x);
    return 0;
}

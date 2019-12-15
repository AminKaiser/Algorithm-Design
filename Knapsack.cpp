#include<bits/stdc++.h>
using namespace std;
#define size 100

void greedy_knapsack(int m, int n, double p[], double w[], double x[])
{
    for(int i = 1; i < n; i++)
    {
        int maximum = i;
        for(int j = i+1; j <= n; j++)
        {
            //if(p[j]>p[maximum]) /// only use for unit price
            if(p[j]/w[j] > p[maximum]/w[maximum])
            {
                maximum = j;
            }
        }
        swap(p[maximum],p[i]);
        swap(w[maximum],w[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        x[i] = 0.0;
    }

    int U = m,i;

    for( i = 1; i <= n; i++)
    {
        if(w[i]>U)
        {
            break;
        }
        x[i] = 1;
        U = U - w[i];
    }

    if(i <= n)
    {
        x[i] = (U/w[i]);
    }
}

void profit_calculation(int n,double p[],double x[])
{
    double sum = 0;

    for(int i = 1; i <= n; i++)
    {
        sum += x[i] * p[i];
    }
    cout<<endl<<sum;
}



int main()
{
    freopen("in.txt","r",stdin);
    double p[size], w[size],x[size];
    int u,n;
    cin>>u>>n; //u = total capacity  n = total element

    // For taking input profit and weight
    for(int i = 1; i<=n; i++)
    {
        cin>>p[i];
    }
    for(int i = 1; i<=n; i++)
    {
        cin>>w[i];
    }

    cout<<endl;
    // To show entered profit
    for(int i = 1; i<=n; i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

    // To show entered weight
    for(int i = 1; i<=n; i++)
    {
        cout<<w[i]<<" ";
    }
    cout<<endl;

    greedy_knapsack(u,n,p,w,x);

    cout<<"After Sorting the Weight and Profit according with Unit :"<<endl;
    for(int i = 1; i <= n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

    for(int i = 1; i <= n;i++)
    {
        cout<<w[i]<<" ";
    }
    cout<<endl;

    cout<<"Portion of each Item : "<<endl;

    for(int i = 1; i <= n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;

    cout<<"Your Total Profit is : ";

    profit_calculation(n,p,x);
    return 0;
}

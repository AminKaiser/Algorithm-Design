#include<bits/stdc++.h>
using namespace std;

int profit[100],deadline[100],position[100],job[100];
int ans1[100];

int Job_Sequence(int n)
{
    /// Using for Swapping
    for(int i=1;i<n;i++)
    {
        int mx = i;
        for(int j=i+1;j<=n;j++)
        {
            if(profit[j]>profit[mx])
                mx = j;
        }
        swap(profit[i],profit[mx]);
        swap(deadline[i],deadline[mx]);
        swap(position[i],position[mx]);
    }

    deadline[0]=0;
    job[0]=0;
    job[1]=1;
    int k = 1;
    for(int i=2;i<=n;i++)
    {
        int right = k;
        while(deadline[job[right]]>deadline[i] && deadline[job[right]]!=right)
            right = right-1;
        if(deadline[job[right]]<=deadline[i] && deadline[i]>right)
        {
            for(int q=k;q>=right+1;q--)
                job[q+1] = job[q];
            job[right+1] = i;
            k++;
        }
    }
    return k;
    //cout<<k<<endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>profit[i];
        cin>>deadline[i];
        position[i] = i;
    }
    cout<<"Index Number   : ";
    for(int i=1;i<=n;i++)
        cout<<position[i]<<" ";
    cout<<endl;
    cout<<"Given Profit   : ";
    for(int i=1;i<=n;i++)
        cout<<profit[i]<<" ";
    cout<<endl;
    cout<<"Given Deadline : ";
    for(int i=1;i<=n;i++)
        cout<<deadline[i]<<" ";
    cout<<endl;

    int ans = Job_Sequence(n);
    cout<<endl;
    cout<<"After Sorting"<<endl;
    cout<<"Index Number   : ";
    for(int i=1;i<=n;i++)
        cout<<position[i]<<" ";
    cout<<endl;
    cout<<"Sorted Profit  : ";
    for(int i=1;i<=n;i++)
        cout<<profit[i]<<" ";
    cout<<endl;
    cout<<"Sorted Deadline: ";
    for(int i=1;i<=n;i++)
        cout<<deadline[i]<<" ";
    cout<<endl;
    cout<<endl;

    cout<<"Selected Profit Position (Order by Selected Job): ";

    for(int i=1;i<=ans;i++)
    {
        cout<<job[i]<<" ";
        ans1[i] = position[job[i]];
    }
    cout<<endl;

    cout<<endl;
    cout<<"Selected Profit Position (Order by Given Index) : ";
    for(int i=1;i<=ans;i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    cout<<endl;
    int total_profit = 0;
    cout<<"Selected Best Profit : ";
    for(int i=1;i<=ans;i++)
    {
        cout<<profit[job[i]]<<" ";
        total_profit+=profit[job[i]];
    }
    cout<<endl<<"Total Profit is : "<<total_profit;
    cout<<endl;
    return 0;
}

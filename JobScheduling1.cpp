#include<bits/stdc++.h>
using namespace std;

int profit[100],deadline[100],position[100],job[100];
int solution_asign[100],selected_job[100],selected_Deadline[100],selected_profit[100];
int solution_vector[100];

int Job_Scheduling(int n)
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
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(job[deadline[i]]==0)
        {
            k++;
            job[deadline[i]] = i;
            solution_asign[k]=deadline[i];
            selected_job[k] = position[i];
            selected_Deadline[k] = deadline[i];
            selected_profit[k] = profit[i];
            solution_vector[position[i]]=1;
        }
        else
        {
            for(int j=deadline[i];j>=1;j--)
            {
                if(job[j] == 0)
                {
                    k++;
                    job[j]=i;
                    solution_asign[k]=j;
                    selected_job[k] = position[i];
                    selected_Deadline[k] = deadline[i];
                    selected_profit[k] = profit[i];
                    solution_vector[position[i]]=1;
                    break;
                }
            }
        }
    }
    return k;
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

    int ans = Job_Scheduling(n);
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
        cout<<job[i]<<" ";
    cout<<endl;

    cout<<"Selected Profit Position (Order by Given Index) : ";
    for(int i=1;i<=ans;i++)
        cout<<position[job[i]]<<" ";
    cout<<endl;
    cout<<endl;

    int total_profit = 0;
    cout<<"Selected Best Profit : ";
    for(int i=1;i<=ans;i++)
    {
        cout<<profit[job[i]]<<" ";
        total_profit+=profit[job[i]];
    }
    cout<<endl<<"Total Profit is : "<<total_profit<<endl;
    cout<<endl;

    cout<<"Solution Vector : ";
    for(int i=1;i<=n;i++)
        cout<<solution_vector[i]<<" ";
    cout<<endl;
    cout<<endl;

    /// Display Job Scheduling Table
    total_profit = 0;
    cout<<"Job Considers \t Deadline  Slot Assign \t\t\t\tSolution      Profit"<<endl;
    for(int i=1;i<=ans;i++)
    {
        cout<<"\tA"<<selected_job[i]<<"\t";
        cout<<"    "<<selected_Deadline[i]<<"\t   ";
        for(int j = 1;j<=i;j++)
        {
            int tmp = solution_asign[j];
            cout<<"["<<tmp-1<<","<<tmp<<"] , ";
        }
        cout<<"\t";
        for(int j=1;j<=ans-i;j++)
            cout<<"\t";
        for(int j = 1;j<=i;j++)
        {
            int tmp = selected_job[j];
            cout<<"A"<<tmp<<", ";
        }
        //cout<<"\t";
        for(int j=1;j<=ans-i;j++)
            cout<<"    ";
        total_profit+=selected_profit[i];
        cout<<total_profit<<endl;
    }
    return 0;
}

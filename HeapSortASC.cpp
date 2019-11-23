#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    void Max_Hapify(int A[],int i,int n)
    {
        int l,r;
        int largest = i;

        l = (2*i);
        r = (2*i)+1;
        if(l<=n && A[l]>A[i])
            largest = l;
        else
            largest = i;
        if(r<=n && A[r]>A[largest])
            largest = r;
         if(largest!=i)
         {
             swap(A[i],A[largest]);
             Max_Hapify(A,largest,n);
         }
    }

    void Build_MaxHeap(int A[],int n)
    {
        for(int i=(n/2);i>=1;i--)
            Max_Hapify(A,i,n);

        for(int i = n; i > 1; i--)
        {
            swap(A[1],A[i]);
            Max_Hapify(A,1,i-1);
        }
    }

    void PrintHeap(int A[],int n)
    {
        cout<<"Array Representation of Heap is : "<<endl;
        for(int i=1;i<=n;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    MaxHeap H;
    int A[100];
    int n;
    cout<<"Enter the Element No : "<<endl;
    cin>>n;
    cout<<"Enter the Elements "<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    H.Build_MaxHeap(A,n);
    H.PrintHeap(A,n);
    return 0;
}

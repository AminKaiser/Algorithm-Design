#include<bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    void Min_Hapify(int A[],int i,int n)
    {
        int l,r;
        int smallest = i;

        l = (2*i);
        r = (2*i)+1;
        if(l<=n && A[l] < A[i])
            smallest = l;
        else
            smallest = i;
        if(r<=n && A[r] < A[smallest])
            smallest = r;

         if(smallest!=i)
         {
             swap(A[i],A[smallest]);
             Min_Hapify(A,smallest,n);
         }
    }

    void Build_MinHeap(int A[],int n)
    {
        for(int i=(n/2); i >= 1; i--)
            Min_Hapify(A,i,n);
    }

    void Heap_Decrese_Key(int A[],int i,int key)
    {
        if(key>A[i])
        {
            cout<<"Error"<<endl;
            return ;
        }
        A[i] = key;
        while(i>1 && A[(i/2)]>A[i])
        {
            swap(A[i],A[i/2]);
            i = i/2;
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
    freopen("inMin.txt","r",stdin);
    MinHeap M;
    int A[100];
    int n;
    cout<<"Enter the Element No : "<<endl;
    cin>>n;
    cout<<"Enter the Elements "<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    int index,key;
    cin>>index>>key;
    M.Build_MinHeap(A,n);
    M.PrintHeap(A,n);
    M.Heap_Decrese_Key(A,index,key);
    M.PrintHeap(A,n);
    return 0;
}

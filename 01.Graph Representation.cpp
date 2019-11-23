#include<bits/stdc++.h>
using namespace std;
int adj_mat[100][100];
class Node
{
public:
    int vertex,weight;
    Node *next;

    Node(int v, int w)
    {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class AdjacentList
{
public:
    Node *head;
    AdjacentList()
    {
        head = NULL;
    }
    void Add(int ver, int wgt, Node **tempHead)
    {
        Node *newNode = new Node(ver,wgt);
        if(*tempHead == NULL)
        {
            *tempHead = newNode;
        }
        else
        {
            Node *last = *tempHead;
            while(last->next != NULL)
            {
                last = last->next;
            }
            last -> next = newNode;
        }

    }

    void DisplayList_Weighted(Node *temp)
    {
        while(temp != NULL)
        {
            cout<<"--"<<temp->vertex<<"|"<<temp->weight<<"| ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void DisplayList_Unweighted(Node *temp)
    {
        while(temp != NULL)
        {
            cout<<"--"<<temp->vertex;
            temp = temp->next;
        }
        cout<<endl;
    }
    void Display_AdjacencyList(int n)
    {
        cout<<"Adjacency Matrix :"<<endl;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cout<<"\t"<<adj_mat[i][j];
            }
            cout<<endl;
        }
    }
};



int main()
{
    freopen("Input Graph 1.txt","r",stdin);
    //freopen("Input Graph 2.txt","r",stdin);
    //freopen("Input Graph 3.txt","r",stdin);
    AdjacentList al[10];
    string type1,type2;
    //int adj_mat[100][100];
    int n,u,v,w;
    cin>>type1>>type2;


    if(type1 == "Undirected" && type2 == "Weighted")
    {
        cin>>n;
        while(cin>>u>>v>>w)
        {
            al[u].Add(v,w,&al[u].head);
            al[v].Add(u,w,&al[v].head);

            adj_mat[u][v] = w;
            adj_mat[v][u] = w;

        }

        cout<<"Adjacency List:"<<endl;
        for(int i = 1; i <= n; i++)
        {
        cout<<"["<<i<<"]";
        al[i].DisplayList_Weighted(al[i].head);
        }
        al[0].Display_AdjacencyList(n);
    }


    else if(type1 == "Directed" && type2 == "UnWeighted")
    {
        cin>>n;
        while(cin>>u>>v)
        {
            al[u].Add(v,1,&al[u].head);
            adj_mat[u][v] = 1;
        }

        cout<<"Adjacency List:"<<endl;
        for(int i = 1; i <= n; i++)
        {
        cout<<"["<<i<<"]";
        al[i].DisplayList_Unweighted(al[i].head);
        }
        al[0].Display_AdjacencyList(n);
    }


    else if(type1 == "Directed" && type2 == "Weighted")
    {
        cin>>n;
        while(cin>>u>>v>>w)
        {
            al[u].Add(v,w,&al[u].head);
            adj_mat[u][v] = w;
        }

        cout<<"Adjacency List:"<<endl;
        for(int i = 1; i <= n; i++)
        {
        cout<<"["<<i<<"]";
        al[i].DisplayList_Weighted(al[i].head);
        }
        cout<<"Adjacency Matrix :"<<endl;
        al[0].Display_AdjacencyList(n);
    }

    return 0;

}


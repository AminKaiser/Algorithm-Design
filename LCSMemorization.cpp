#include<bits/stdc++.h>
using namespace std;

string str1;
string str2;
int CS[100][100];
int a = 0, b = 0;

int LCS(int fs,int se)
{
    for(int i = fs; i <= a; i++)
    {
        for(int j = se;j <= b; j++)
        {
            if(str1[i-1] == str2[j-1])
                CS[i][j] = 1 + CS[i-1][j-1];
            else
                CS[i][j] = max(CS[i-1][j],CS[i][j-1]);
        }
    }
}

int main()
{
    char r[100];
    int k = 0;
    cin>>str1>>str2;


    while (str1[a] != '\0')
    {
        ++a;
    }
    while (str2[b] != '\0')
    {
        ++b;
    }

    cout<<"Result is : "<<endl;

    for(int st = 1; st <= b; st++){
        for (int i=1; i<=a; i++)
        {
            for (int j=1; j<=b; j++)
            {
                (CS[i][j] = 0);
            }
        }



    LCS(1,st);

    cout<<"LCS: "<<CS[a][b]<<endl;


    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
            {
                cout<<CS[i][j]<<" ";
            }

        cout<<endl;
    }

    int maximum = CS[a][b];
    for(int l = a; l>=1; l--)
    {
        for(int t = 0; t < k; t++)
        {
            r[t] = 0;
        }
        k = 0;
        if(CS [l][b] == maximum)
        {
            int i = l;
            int j = b;

            while(j>0 && i>0)
            {
                if(CS[i][j] == CS[i][j-1])
                    j = j-1;
                else if(CS[i][j] == CS[i-1][j])
                    i = i-1;
                else
                {
                    r[k++] = str2[j-1];
                    i = i-1;
                    j = j-1;
                }
            }
            cout<<endl<<"The Result is :"<<endl;
            for(int l = k-1; l >=0; l--)
            {
                cout<<r[l];
            }

            cout<<endl;
        }
    }
    }
    return 0;
}

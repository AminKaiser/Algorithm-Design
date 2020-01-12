#include<bits/stdc++.h>
using namespace std;

string str1;
string str2;
int CS[100][100];

int LCS(int i, int j)
{
    if(str1[i] == '\0' || str2[j] == '\0')
    {
        return 0;
    }
    else if(CS[i][j] != -1)
    {
        return CS[i][j];
    }

    else if(str1[i] == str2[j])
    {
        CS[i][j] = 1 + LCS(i+1,j+1);
        return CS[i][j];
    }
    else
    {
        CS[i][j] = max(LCS(i+1,j),LCS(i,j+1));
        return CS[i][j];
    }
}

int main()
{
    memset(CS,-1,sizeof(CS));
     cout<<"Enter First String"<<endl;
     cin>>str1;
     cout<<"Enter Second String"<<endl;
     cin>>str2;
//
//    int a =0, b = 0;
//    while (str1[a] != '\0')
//    {
//        ++a;
//    }
//    while (str2[b] != '\0')
//    {
//        ++b;
//    }

    for (int i=0; i<=100; i++)
    {
        for (int j=0; j<=100; j++)
        {
            CS[i][j] = -1;
        }
    }


     int r = LCS(0,0);
     cout<<r;

}

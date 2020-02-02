#include<bits/stdc++.h>
using namespace std;

string str1,str2,longest="";
int CS[100][100];

int LCS(int i,int j)
{
    if(str1[i]=='\0' || str2[j]=='\0')
        return 0;
    else if(CS[i][j]!=-1)
        return CS[i][j];
    else if(str1[i]==str2[j])
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

void LCS_Display(int i,int j)
{
    if(str1[i]=='\0' || str2[j]=='\0')
    {
        cout<<longest<<endl;
        return;
    }
    else if(str1[i]==str2[j])
    {
        longest+=str2[j];
        LCS_Display(i+1,j+1);
    }
    else
    {
        if(CS[i][j+1]>CS[i+1][j])
            LCS_Display(i,j+1);
        else
            LCS_Display(i+1,j);
    }
}

int main()
{
    memset(CS,-1,sizeof(CS));
    int result;
    cin>>str1>>str2;
    result = LCS(0,0);
    cout<<result<<endl;
    LCS_Display(0,0);
    return 0;
}

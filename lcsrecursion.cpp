#include<bits/stdc++.h>
using namespace std;

string str1,str2,longest="";

int LCS(int i,int j)
{
    if(str1[i]=='\0' || str2[j]=='\0')
        return 0;
    else if(str1[i]==str2[j])
        return 1 + LCS(i+1,j+1);
    else
        return max(LCS(i+1,j),LCS(i,j+1));
}

void LCS_Display(int i,int j)
{
    if(str1[i]=='\0' || str2[j]=='\0')
    {
        cout<<longest<<endl;
        return ;
    }
    else if(str1[i]==str2[j])
    {
        longest+=str2[j];
        LCS_Display(i+1,j+1);
    }
    else
    {
        if(LCS(i+1,j)>LCS(i,j+1))
            LCS_Display(i+1,j);
        else
            LCS_Display(i,j+1);
    }
}

int main()
{
    int result;
    cin>>str1>>str2;
    result = LCS(0,0);
    cout<<result<<endl;
    LCS_Display(0,0);
    return 0;
}

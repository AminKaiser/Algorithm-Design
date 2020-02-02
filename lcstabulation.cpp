#include<bits/stdc++.h>
using namespace std;

string str1,str2;
int CS[100][100];

int LCS(int str1_len,int str2_len)
{
    for(int i=1;i<=str1_len;i++)
    {
        for(int j=1;j<=str2_len;j++)
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
    stack<char>stk;
    int first_start,second_start;
    cin>>str1>>str2;
    LCS(str1.size(),str2.size());
    cout<<"The LCS of these string = "<<CS[str1.size()][str2.size()]<<endl;

//
//    for(int i=0;i<=str1.size();i++)
//    {
//        for(int j=0;j<=str2.size();j++)
//            cout<<CS[i][j]<<" ";
//        cout<<endl;
//    }

        int i = str1.size();
        int j = str2.size();
        while(j>0 && i>0)
        {
            if(CS[i][j] == CS[i][j-1])
                j = j-1;
            else if(CS[i][j] == CS[i-1][j])
                i = i-1;
            else
            {
                stk.push(str2[j-1]);   /// Alternate way stk.push(str1[i-1])
                i = i-1;
                j = j-1;
            }
        }

        while(!stk.empty())
        {
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
    return 0;
}

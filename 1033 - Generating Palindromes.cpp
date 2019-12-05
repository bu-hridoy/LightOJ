/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1033
#include<bits/stdc++.h>
using namespace std;
string A,B;
int visited[101][101];
int dp[101][101];


int cal(int i, int j)
{
    if(A[i]=='\0' || B[j]=='\0')
        return 0;
    if(visited[i][j])
        return dp[i][j];
    int ans=0;
    if(A[i]==B[j])
        ans=1+cal(i+1, j+1);
    else
    {
        int a=cal(i, j+1);
        int b=cal(i+1, j);
        ans=max(a,b);
    }
    visited[i][j]=1;
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        memset(visited,0,sizeof(visited));
   cin>>A;
   B=A;
   reverse(A.begin(),A.end());
   int l=A.length();
   int ans= l-cal(0,0);
   printf("Case %d: %d\n",i,ans);
    }
}

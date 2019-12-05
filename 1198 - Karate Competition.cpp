/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1198

#include<bits/stdc++.h>
using namespace std;
int arr[55],n,arr2[55],dp[55][55];

int fun(int i,int j)
{
    if(i>=n || j>=n)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int sum2=0;
    if(arr[i]>arr2[j])
    sum2=2+fun(i+1,j+1);

    int sum1=0;
    if(arr[i]==arr2[j])
       sum1=max(fun(i,j+1),1+fun(i+1,j+1));

   int sum=0;
   if(arr[i]<arr2[j])
         sum=max(fun(i+1,j),fun(i,j+1));

    int res=max(sum1,max(sum,sum2));

    dp[i][j]=res;

    return res;


}

int main()
{
    int t=0, T;
    scanf("%d",&T);

    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        memset(arr,0,sizeof(arr));
        memset(arr2,0,sizeof(arr2));

        scanf("%d",&n);

        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);

        for(int i=0; i<n; i++)
            scanf("%d",&arr2[i]);

        sort(arr,arr+n);
        reverse(arr,arr+n);
        sort(arr2,arr2+n);
        reverse(arr2,arr2+n);
        int ans=fun(0,0);

        printf("Case %d: %d\n",++t,ans);
    }
}

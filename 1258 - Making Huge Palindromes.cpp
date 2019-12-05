/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1258

#include<bits/stdc++.h>
using namespace std;
string A,B;

int KMP()
{
    int l=B.length();
    int prifix[l+2];
    prifix[0]=0;
    int j=0,i=1;

    while(i<l)
    {
        if(B[i]==B[j])
        {
            j++;
            prifix[i]=j;
            i++;
        }
        else
        {
            if(j>0)
            {
                j=prifix[j-1];
            }
            else
            {
                prifix[i]=0;
                i++;
            }
        }

    }

     i=0;
     j=0;
     int k=0;

    while(i<l)
    {
        if(A[i]==B[j])
            {
                i++;
                j++;
            }
        else
        {
            if(j>0)
                j=prifix[j-1];
            else
                i++;
        }
    }
    return j;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);

    while(T--)
    {
        cin>>B;
        A=B;
        int l=A.length();
        reverse(B.begin(),B.end());
        int ans=KMP();
        printf("Case %d: %d\n",++t,2*l-ans);
    }
}

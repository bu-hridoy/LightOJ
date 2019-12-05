    /// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1004

    #include<bits/stdc++.h>
    using namespace std;

    int N,v;
    int dp[201][201];
    vector<int>a[201];


    int call(int i, int j)
    {
        if(i>=0 && i<2*N-1 && j>=0 && j<a[i].size())
        {
            if(dp[i][j]!=-1)
                return dp[i][j];

            int p=-1;
            p=max(p,call(i+1, j)+a[i][j]);
            if(i<N-1)
            {
                p=max(p,call(i+1,j+1)+a[i][j]);
            }
            else if(i>=N-1){
                p=max(p,call(i+1, j-1)+a[i][j]);
            }

            return dp[i][j]=p;
        }
        else
            return 0;
    }

    int main()
    {
        int T;
        cin>>T;
        for(int t=1; t<=T; t++)
        {
            memset(dp,-1,sizeof(dp));

            cin>>N;
            for(int i=0; i<N; i++)
            {
                a[i].clear();
                for(int j=0; j<=i; j++)
                {
                    cin>>v;
                    a[i].push_back(v);
                }
            }
            int l=N-1;

            for(int i=N; i<2*N-1; i++)
            {
                a[i].clear();
                for(int j=0; j<l; j++)
                {
                    cin>>v;
                    a[i].push_back(v);
                }
                l--;
            }

            printf("Case %d: %d\n",t,call(0,0));
        }
    }


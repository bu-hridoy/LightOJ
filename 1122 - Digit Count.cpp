///Problem Link - http://lightoj.com/volume_showproblem.php?problem=1122
#include <bits/stdc++.h>
using namespace std ;

int N, M;
long long res;

int dp[11][11];
int A[11];

int solve( int m, int n)
{
    if (m == 1)
        return 1 ;

    if (dp[m][n] == - 1 )
    {
       int total = 0;

    for ( int i = 1; i <= N; i++)
    {
        if (abs (A[n] - A[i]) <= 2 ){

        total += solve(m- 1, i);

        }
    }
    dp[m][n] = total;
    }

  return dp[m][n];
}
int main()
{
    int T,i;
    cin >> T;
    getchar ();

    for (int t = 1; t <= T; t++)
    {
        memset(dp,-1,sizeof(dp));

        cin >> N >> M;
        for (i = 1 ; i <= N; i++)
        cin >> A[i];

        res = 0;
        for (i = 1 ; i <= N; i++)
            res += solve(M, i);

        printf( "Case %d: %lld\n" , t, res);

    }

    return 0;
}

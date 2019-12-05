/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1162

#include<bits/stdc++.h>
using namespace std;

/*-------------------------- HRIDOY ROY -------------------------*/

#define     fRead           freopen("input.txt","r",stdin)
#define     fWrite          freopen("output.txt","w",stdout)

#define     I(X)            scanf("%d",&(X))
#define     II(X, Y)        scanf("%d%d",&(X),&(Y))
#define     III(X,Y,Z)      scanf("%d%d%d",&(X),&(Y),&(Z))
#define     IL(X)           scanf("%lld",&(X))
#define     IIL(X, Y)       scanf("%lld%lld",&(X),&(Y))
#define     pb              push_back
#define     popb            pop_back
#define     lld             long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000009
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     show            printf("---***---")
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     PLL             pair<lld,lld>
#define     MAX             100000000000014
#define     MIN             -100000000000014
#define     gti             greater<int>
#define     gtL             greater<lld>
#define     PI1             acos(-1.0)
#define     pi2             2.0*acos(0.0)
#define     endl            '\n'

//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}

int Day12[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prime100[]={2, 3, 5, 7, 11, 13, 17, 19, 23,29,31, 37, 41, 43, 47, 53, 59,61, 67,71, 73, 79, 83, 89, 97, 101, 103 };

template <typename T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);}
template <typename T> inline T GCD (T a,T b ) {a = abs(a);b = abs(b); if(a < b) swap(a, b); while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <typename T> inline T LCM(T x,T y){T tp = GCD(x,y);if( (x / tp) * 1. * y > 9e18) return 9e18;return (x / tp) * y;}
template <typename T> inline T BIGMOD(T A,T B,T M = MOD){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T BigMod(T A,T B,T M){T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}

//----------------------------- O.D.Y.W.F.M ----------------------------------//

#define mx 100005
vector<int>V[mx],cost[mx];
int Par[mx][20],Par_MAX[mx][20],Par_MIN[mx][20];
int level[mx],dis[mx];

void INIT()
{
    for(int i=1; i<=100001; i++)
    {
        V[i].clear();
        cost[i].clear();
    }

}

void dfs(int node, int L, int from)
{
    Par[node][0]=from;
    level[node]=L;

    int sz=V[node].size();

    for(int i=0; i<sz; i++)
    {
        int v=V[node][i];
        if(v!=from)
        {
            dis[v]=cost[node][i];
            dfs(v,L+1,node);
        }
    }
}

void Build(int n)
{
    Par_MAX[1][0]=0;
    Par_MIN[1][0]=INT_MAX;
    Par[1][0]=1;

    for(int i=2; i<=n; i++)
    {
        Par_MAX[i][0]=dis[i];
        Par_MIN[i][0]=dis[i];
    }

    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(Par[i][j-1]!=-1)
            {
                Par[i][j]=Par[Par[i][j-1]][j-1];
                Par_MAX[i][j]=max(Par_MAX[i][j-1],Par_MAX[Par[i][j-1]][j-1]);
                Par_MIN[i][j]=min(Par_MIN[i][j-1],Par_MIN[Par[i][j-1]][j-1]);

            }
        }
    }
}

pii query(int a, int b)
{
    if(level[a]<level[b]) swap(a,b);

    int ans_max=0;
    int ans_min=INT_MAX;

    for(int i=18; i>=0; i--)
    {
        if(level[a]-(1<<i) >= level[b])
        {
            ans_max=max(ans_max,Par_MAX[a][i]);
            ans_min=min(ans_min,Par_MIN[a][i]);
            a=Par[a][i];
        }
    }

    if(a==b)
        return pii(ans_min,ans_max);

     for(int i=18; i>=0; i--)
    {
        if(Par[a][i]!=-1 && Par[a][i]!=Par[b][i])
        {
            ans_max=max(ans_max,max(Par_MAX[a][i],Par_MAX[b][i]));
            ans_min=min(ans_min,min(Par_MIN[a][i],Par_MIN[b][i]));
            a=Par[a][i];
            b=Par[b][i];
        }
    }
      ans_max=max(ans_max,max(dis[a],dis[b]));
      ans_min=min(ans_min,min(dis[a],dis[b]));

      return pii(ans_min,ans_max);
}

int main()
{
    int t=0,T;
    I(T);
    while(T--){
    int n;
    I(n);

    INIT();

    for(int i=1; i<n; i++)
    {
        int x,y,w;
        III(x,y,w);
        V[x].pb(y);
        V[y].pb(x);
        cost[x].pb(w);
        cost[y].pb(w);
    }

    memset(Par, -1 , sizeof Par);
    dis[1]=0;
    dfs(1,0,1);
    Build(n);

    int q;
    I(q);

    printf("Case %d:\n",++t);

    while(q--)
    {
        int a,b;
        II(a,b);
        pii ans=query(a,b);
        printf("%d %d\n",ans.f,ans.s);
    }
    }

}

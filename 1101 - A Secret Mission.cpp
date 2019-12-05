/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1101

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


#define mx 50005
int Parent[mx];
int Par[mx][20];
int Max_Table[mx][20];
vector<int>GP[mx];
vector<int>cost[mx];
int level[mx], dis[mx];
vector<pair<int, pair<int,int> > >V;


int Find(int A)
{
    if(A==Parent[A])
        return Parent[A];

    Parent[A]=Find(Parent[A]);
    return Parent[A];
}

void dfs(int node, int L, int from)
{
    Par[node][0]=from;
    level[node]=L;

    int sz=GP[node].size();

    for(int i=0; i<sz; i++)
    {
        int v=GP[node][i];
        if(v!=from)
        {
            dis[v]=cost[node][i];
            dfs(v,L+1,node);
        }
    }
}

void Build_Table(int node)
{
    Max_Table[1][0]=0;
    Par[1][0]=1;

    for(int i=2; i<=node; i++)
    {
        Max_Table[i][0]=dis[i];
    }

    for(int j=1; (1<<j)<node; j++)
    {
        for(int i=1; i<=node; i++)
        {
            if(Par[i][j-1]!=-1)
            {
                Par[i][j]=Par[Par[i][j-1]][j-1];
                Max_Table[i][j]=max(Max_Table[i][j-1], Max_Table[Par[i][j-1]][j-1]);
            }
        }
    }

}

int query(int a, int b)
{
    if(level[a]<level[b]) swap(a,b);

    int ans_max=0;


    for(int i=18; i>=0; i--)
    {
        if(level[a]-(1<<i) >= level[b])
        {
            ans_max=max(ans_max,Max_Table[a][i]);
            a=Par[a][i];
        }
    }

    if(a==b)
        return (ans_max);

     for(int i=18; i>=0; i--)
    {
        if(Par[a][i]!=-1 && Par[a][i]!=Par[b][i])
        {
            ans_max=max(ans_max,max(Max_Table[a][i],Max_Table[b][i]));
            a=Par[a][i];
            b=Par[b][i];
        }
    }
      ans_max=max(ans_max,max(dis[a],dis[b]));

      return (ans_max);
}
int main()
{
    int T,t=0;
    I(T);
    while(T--){

    int node,E;
    II(node,E);

    V.clear();
    while(E--)
    {
        int a,b,w;
        III(a,b,w);
        V.pb(mp(w,mp(a,b)));
    }

    for(int i=1; i<=node; i++)
    {
        Parent[i]=i;
        GP[i].clear();
        cost[i].clear();
        level[i]=-1;
    }
    memset(Max_Table, -1, sizeof Max_Table);
    memset(Par, -1, sizeof Par);

    sort(V.begin(),V.end());
    int Sz=V.size(),Cnt=0;

    for(int i=0; i<Sz && Cnt<node-1; i++)
    {
        int a=V[i].second.first;
        int b=V[i].second.second;
        int w=V[i].first;

        int N=Find(a);
        int M=Find(b);

        if(N!=M)
        {
            GP[a].pb(b);
            GP[b].pb(a);

            cost[a].pb(w);
            cost[b].pb(w);
            Parent[M]=N;
            Cnt++;
        }
    }

    dis[1]=0;
    dfs(1,0,1);
    Build_Table(node);

    int q;
    I(q);
    printf("Case %d:\n",++t);
    while(q--)
    {
        int x,y;
        II(x,y);
        int ans=query(x,y);
        printf("%d\n",ans);
    }
    }
}

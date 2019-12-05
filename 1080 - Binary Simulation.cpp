/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1080

#include<bits/stdc++.h>
using namespace std;
int Arr[100005];
int Lazy[400005];

void update(int node, int S, int E, int i, int j)
{
    if(Lazy[node] > 0){
        if(S != E){
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        else{
            Arr[S] += Lazy[node];
        }
        Lazy[node] = 0;
    }
    if(S > j || E < i)
        return;
    if(S >= i && E <= j){
        Lazy[node] += 1;
        return;
    }

    int L = 2 * node;
    int R = L + 1;
    int mid = (S+ E)/2;

    update(L , S, mid , i ,j);
    update(R , mid + 1 , E, i , j);
}

int query(int node, int S, int  E, int i)
{
    if(Lazy[node] > 0){
        if(S != E){
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        else{
            Arr[S] += Lazy[node];
        }
        Lazy[node] = 0;
    }
    if(S >= i && E <= i){
        Arr[S] %= 2;
        return Arr[S];
    }

    int L = 2 * node;
    int R = L + 1;
    int mid = (S+ E)/2;

    if(i>=S && i <= mid)
       return query(L , S , mid, i);
    else return query(R, mid+1 , E, i);
}

int main()
{
    int T,t = 0;

    ios_base::sync_with_stdio(false);
    //scanf("%d",&T);
    cin>>T;
    while(T--){
    memset(Lazy , 0, sizeof Lazy);
    memset(Arr, 0, sizeof Arr);

    string S;
    cin>>S;

    int n = S.length();
    for(int i = 0 ; i < n; i++){
        if(S[i] == '1')
            Arr[i+1] = 1;
    }

    int q,flag = 0;
    //scanf("%d",&q);
    cin>>q;

    while(q--){
        char A;
        cin>>A;

        if(A == 'I'){
            int a,b;
            cin>>a>>b;
            update(1,1,n,a,b);
        }
        else{
            int a;
            cin>>a;
            int ans = query(1,1,n,a);
            if(flag == 0){
                printf("Case %d:\n",++t);
                flag = 1;
            }
            printf("%d\n",ans);
        }
    }
    }
}

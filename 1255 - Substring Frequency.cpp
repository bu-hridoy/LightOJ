/// Problem Link - http://lightoj.com/volume_showproblem.php?problem=1255

#include<bits/stdc++.h>
using namespace std;
int Count;


void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;
    int i = 1;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len-1];

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    computeLPSArray(pat,M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N)
    {
        if (pat[j] == txt[i]){
            j++;
            i++;
        }
        if (j == M){
            Count++;
            j = lps[j-1];
        }

        else if (i < N && pat[j] != txt[i]){
            if (j != 0)
               j = lps[j-1];

            else
               i = i+1;
        }
    }
}
int main()
{
    char pat[1000005], txt[1000005];
    int T;
    cin>>T;
    for(int i=1; i<=T; i++)
    {

    cin>>txt;
    cin>>pat;


    KMPSearch( pat, txt);
    printf("Case %d: %d\n",i,Count);
    Count=0;
    }
}

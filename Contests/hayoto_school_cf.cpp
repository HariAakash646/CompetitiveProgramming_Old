#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        int e = 0;
        int o = 0;
        int a;
        vi oidx, eidx;
        frange(i, n)
        {
            scd(a);
            if (a % 2)
            {
                o++;
                oidx.pb(i + 1);
            }
            else
            {
                e++;
                eidx.pb(i + 1);
            }
        }
        if (o >= 3)
        {
            printf("YES\n");
            frange(i, 3)
            {
                printf("%d ", oidx[i]);
            }
            printf("\n");
        }
        else if (e >= 2 && o >= 1)
        {
            printf("YES\n");
            frange(i, 2)
            {
                printf("%d ", eidx[i]);
            }
            printf("%d", oidx[0]);
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
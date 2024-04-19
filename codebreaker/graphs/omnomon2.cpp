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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int n;
vvi graph;
vll dp1, dp2, sub, nsub;

void dfs1(int x, int prev)
{
    sub[x] = 1;
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs1(e, x);
            sub[x] += sub[e];
            dp1[x] += dp1[e] + sub[e];
        }
    }
}

void dfs2(int x, int prev)
{
    if (prev != 0)
        dp2[x] = (dp2[prev] + n - sub[prev]) + (dp1[prev] - (dp1[x] + sub[x]) + (sub[prev] - sub[x]));
    for (auto e : graph[x])
    {
        if (e != prev)
        {
            dfs2(e, x);
        }
    }
}

int main()
{

    scd(n);
    graph = vvi(n + 1);
    dp1 = dp2 = sub = nsub = vll(n + 1);
    frange(i, n - 1)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    lli tot = 0;
    forr(i, 1, n + 1) tot += dp1[i] + dp2[i];
    printf("%lld", tot);
}
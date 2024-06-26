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
    int n;
    scd(n);
    vector<lli> avec(n);
    vector<lli> bvec(n);
    frange(i, n) sclld(avec[i]);
    frange(i, n) sclld(bvec[i]);
    lli tot = 0;
    frange(i, n)
    {
        tot += avec[i] * bvec[i];
    }
    vector<vector<lli>> dp(n, vector<lli>(n, tot));
    lli m = tot;
    for (int i = n - 2; i >= 0; i--)
    {
        forr(j, i + 1, n)
        {
            dp[i][j] = dp[i + 1][j - 1] + avec[i] * bvec[j] + bvec[i] * avec[j] - avec[i] * bvec[i] - avec[j] * bvec[j];
            m = max(m, dp[i][j]);
        }
    }
    printf("%lld", m);
}
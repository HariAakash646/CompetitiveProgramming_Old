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

lli mod = 1e9 + 7;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    m *= 2;
    vector<vector<lli>> dp(n + 1, vector<lli>(m + 1));
    frange(i, n + 1)
    {
        dp[i][0] = 1;
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    printf("%lld", dp[n][m]);
}
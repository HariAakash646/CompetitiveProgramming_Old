#include <bits/stdc++.h>

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

int main()
{
    int n;
    scd(n);
    int x;
    scd(x);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vector<vi> dp(1 << n, vi(n + 1, -1));
    dp[0][0] = 0;
    forr(i, 0, 1 << n)
    {
        forr(j, 1, n + 1)
        {
            if (j > 0 && dp[i][j - 1] != -1)
            {
                dp[i][j] = 0;
                continue;
            }
            frange(k, n)
            {
                if (i & (1 << k))
                {
                    if (dp[i ^ (1 << k)][j - 1] != -1)
                    {
                        dp[i][j] = vec[k];
                        break;
                    }
                    else if (dp[i ^ (1 << k)][j] != -1)
                    {
                        if (dp[i][j] == -1)
                        {
                            if (dp[i ^ (1 << k)][j] + vec[k] <= x)
                                dp[i][j] = dp[i ^ (1 << k)][j] + vec[k];
                        }
                        else
                            dp[i][j] = min(dp[i][j], dp[i ^ (1 << k)][j] + vec[k]);
                    }
                }
            }
        }
    }
    int mi = n + 1;
    frange(i, n + 1)
    {
        if (dp[(1 << n) - 1][i] != -1)
        {
            mi = i;
            break;
        }
    }
    printf("%d", mi);
}
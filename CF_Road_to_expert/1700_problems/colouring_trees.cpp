// Some implementation bug
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

lli inf = 1e13;

int main()
{
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    vi vec(n + 1);
    frange(i, n)
    {
        scd(vec[i + 1]);
    }
    vvi cost(n + 1, vi(m + 1));
    frange(i, n)
    {
        frange(j, m)
        {
            scd(cost[i + 1][j + 1]);
        }
    }
    vector<vector<vll>> dp(k + 1, vector<vll>(n + 1, vll(m + 1, inf)));
    dp[0][0][0] = 0;
    frange(j, m + 1)
    {
        dp[0][0][j] = 0;
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            if (vec[i])
            {
                dp[0][i][j] = inf;
            }
            else
            {
                dp[0][i][j] = dp[0][i - 1][j];
            }
        }
    }
    forr(i, 1, k + 1)
    {
        forr(j, 1, n + 1)
        {
            forr(l, 1, m + 1)
            {
                if (j < i)
                {
                    dp[i][j][l] = inf;
                }
                else if (vec[j])
                {
                    if (vec[j] != l)
                        dp[i][j][l] = inf;
                    else
                    {
                        dp[i][j][l] = dp[i][j - 1][l];
                        forr(p, 1, m + 1)
                        {
                            if (p == l)
                                continue;
                            dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j - 1][p]);
                        }
                    }
                }
                else
                {
                    dp[i][j][l] = dp[i][j - 1][l] + cost[j][l];
                    forr(p, 1, m + 1)
                    {
                        if (p == l)
                            continue;
                        dp[i][j][l] = min(dp[i][j][l], dp[i - 1][j - 1][p] + cost[j][l]);
                    }
                }
            }
        }
    }
    lli mi = inf;
    forr(i, 1, m + 1)
    {
        mi = min(dp[k][n][i], mi);
    }
    printf("%lld", mi);
}
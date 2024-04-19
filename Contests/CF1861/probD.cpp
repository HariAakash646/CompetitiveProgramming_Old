#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    int t;
    scd(t);

    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        vi dp1(n), dp2(n);
        dp1[0] = 1;
        forr(i, 1, n)
        {
            dp1[i] = dp1[i - 1];
            if (vec[i] >= vec[i - 1])
                dp1[i]++;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            dp2[i] = dp2[i + 1];
            if (vec[i] >= vec[i + 1])
                dp2[i]++;
        }
        int mi = min(dp1[n - 1], dp2[0]);
        frange(i, n - 1)
        {
            mi = min(mi, dp1[i] + dp2[i + 1]);
        }
        printf("%d\n", mi);
    }
}
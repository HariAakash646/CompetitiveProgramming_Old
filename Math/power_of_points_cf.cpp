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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vii vec(n);
        frange(i, n) scd(vec[i].f);
        frange(i, n) vec[i].s = i;
        lli tot = 0;
        sort(all(vec));
        frange(i, n)
        {
            tot += vec[i].f - vec[0].f;
        }
        vll out(n);
        out[vec[0].s] = tot + n;
        forr(i, 1, n)
        {
            tot -= lli(vec[i].f - vec[i - 1].f) * (n - i);
            tot += lli(vec[i].f - vec[i - 1].f) * i;
            out[vec[i].s] = tot + n;
        }
        for (auto e : out)
            printf("%lld ", e);
        printf("\n");
    }
}
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
typedef vector<vll> vvll;


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

const lli mod = 1e9 + 7;

vvll matmul(vvll a, vvll b)
{
    int r1 = a.size();
    int c1 = a[0].size();
    int r2 = b.size();
    int c2 = b[0].size();
    vvll prod(r1, vll(c2));
    frange(i, r1)
    {
        frange(j, c2)
        {
            frange(k, c1)
            {
                prod[i][j] += (a[i][k] * b[k][j]) % mod;
                prod[i][j] %= mod;
            }
        }
    }
    return prod;
}
 
vvll matexp(vvll a, lli n)
{
 
    vvll out(a.size(), vll(a.size()));
    frange(i, a.size())
    {
        out[i][i] = 1;
    }
    if(n == 0) return out;
    out = matexp(a, n/2);
 
    out = matmul(out, out);
 
    if(n % 2) out = matmul(out, a);
 
    return out;
}

int main() {
    // usaco();
    int m, n;

    scd(m);
    scd(n);

    vi v1(m), v2(m);
    frange(i, m) scd(v1[i]);
    frange(i, m) scd(v2[i]);

    vvll cnt(m, vll(m));
    frange(i, m) {
        frange(j, m) {
            cnt[i][j] = v1[i] * (v2[j] + v1[j]) + v2[i] * v1[j];
        }
    }

    cnt = matexp(cnt, n);
    
    lli tot = 0;
    frange(i, m) {
        tot += cnt[0][i];
        tot %= mod;
    }
    printf("%lld", tot);
}
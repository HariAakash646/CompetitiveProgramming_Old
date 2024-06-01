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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);

        sort(all(vec));

        vi v2;

        int v = vec[0];

        for(auto e : vec) {
            if(e % v) v2.pb(e);
        }

        bool yes = true;
        if(v2.size()) {
            v = v2[0];
            for(auto e : v2) {
                if(e % v) yes = false;
            }
        }
        if(yes) printf("YES\n");
        else printf("NO\n");
    }
}
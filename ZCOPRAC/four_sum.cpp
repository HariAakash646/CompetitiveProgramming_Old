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

int main() {
    // usaco();
    int n, t;
    scd(n);
    scd(t);
        
    vi vec(n);

    frange(i, n) scd(vec[i]);

    vi cnt(t+1);
    if(vec[0] + vec[1] <= t)
    cnt[vec[0] + vec[1]]++;
    lli tot = 0;
    forr(i, 2, n) {
        forr(j, i+1, n) {
            if(t - (vec[i] + vec[j]) >= 0)
                tot += cnt[t - (vec[i] + vec[j])];
        }
        forr(j, 0, i) {
            if(vec[i] + vec[j] <= t)
                cnt[vec[i]+vec[j]]++;
        }
    }
    printf("%lld", tot);
}
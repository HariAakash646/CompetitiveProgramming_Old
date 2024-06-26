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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void usaco()
{
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) {
            scd(vec[i]);
        }
        sort(all(vec));
        vi out(n);
        int id = 0;
        for(int i=0; i<n; i+=2) {
            out[i] = vec[id];
            id++;
        }
        for(int i=1; i<n; i+=2) {
            out[i] = vec[id];
            id++;
        }
        bool done = false;
        bool curr = true;
        forr(i, 1, n) {
            if(out[i] == out[i-1]) curr = false;
        } 
        if(curr) {
            done = true;
            for(auto e : out) printf("%d ", e);
            printf("\n");
            continue;
        }
        sort(all(vec), greater<int>());
        out=vi(n);
        id = 0;
        for(int i=0; i<n; i+=2) {
            out[i] = vec[id];
            id++;
        }
        for(int i=1; i<n; i+=2) {
            out[i] = vec[id];
            id++;
        }
        curr = true;
        forr(i, 1, n) {
            if(out[i] == out[i-1]) curr = false;
        } 
        if(curr) {
            done = true;
            for(auto e : out) printf("%d ", e);
            printf("\n");
            continue;
        }
        printf("-1\n");

    }
}
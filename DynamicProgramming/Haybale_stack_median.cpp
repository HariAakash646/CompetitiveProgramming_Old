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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    // freopen("stacking.in", "r", stdin);
    // freopen("stacking.out", "w", stdout);

    int n, k;
    scd(n);
    scd(k);
    int a, b;
    vi vec(n + 2);
    frange(i, k)
    {
        scd(a);
        scd(b);
        vec[a]++;
        vec[b + 1]--;
    }
    vi stacks(n);
    stacks[0] = vec[1];
    forr(i, 1, n, 1)
    {
        stacks[i] = vec[i + 1] + stacks[i - 1];
    }
    sort(stacks.begin(), stacks.end());
    printf("%d", stacks[stacks.size() / 2]);
    return 0;
}
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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
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

int main()
{
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b;
    scd(n);
    scd(k);
    scd(b);
    vi pref(n + 1, 0);
    vi vec(n + 1, 0);
    frange(i, b)
    {
        int idx;
        scd(idx);
        vec[idx] = 1;
    }
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vec[i];
    }
    int mi = 1e9;
    forr(i, k, n + 1)
    {
        mi = min(pref[i] - pref[i - k], mi);
    }
    printf("%d", mi);
}
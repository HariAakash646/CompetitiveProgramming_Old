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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vvi vec(n, vi(n));
        frange(i, n)
        {
            frange(j, n - 1)
                scd(vec[i][j]);
        }
        vi out;
        frange(i, n)
        {
            vi cn(n + 1, 0);
            frange(j, n)
            {
                cn[vec[j][i]]++;
            }
            int e = max_element(all(cn)) - cn.begin();
            out.pb(e);
            frange(j, n)
            {
                if (vec[j][i] != e)
                {
                    vec[j].insert(vec[j].begin() + i, e);
                }
            }
            printf("%d ", e);
        }
        printf("\n");
    }
}
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
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
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
    int n, m;
    scd(n);
    scd(m);
    vector<lli> vec1(n);
    frange(i, n)
    {
        sclld(vec1[i]);
    }
    vector<lli> vec2(m);
    vii vec3(n);
    frange(i, m)
    {
        int st, en;
        sclld(vec2[i]);
        scd(st);
        scd(en);
        vec3[i] = {st, en};
    }
    sort(all(vec1));
    sort(all(vec2));
    lli tot = 0;
    int idx = 0;
    frange(i, m)
    {
        frange(j, vec3[i].s)
        {
            tot += abs(vec1[idx] - vec2[i]);
            idx++;
        }
    }
    if (idx == n)
        printf("%lld", tot);
    else
        printf("-1");
}
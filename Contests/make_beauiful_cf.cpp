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
#define pb push_back
#define f first
#define s second
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
    int t;
    scd(t);
    frange(i, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(j, n)
        {
            scd(vec[j]);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        if (vec[0] == vec[n - 1])
        {
            printf("NO\n");
        }
        else
        {
            int tmp = vec[1];
            vec[1] = vec[n - 1];
            vec[n - 1] = tmp;
            printf("YES\n");
            for (auto e : vec)
            {
                printf("%d ", e);
            }
            printf("\n");
        }
    }
}
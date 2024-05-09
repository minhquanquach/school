#include <bits/stdc++.h>
using namespace std;
template <typename _Tp> bool minimize(_Tp &__a, const _Tp &__b) { if (__a > __b) { __a = __b; return true; } return false; }
template <typename _Tp> bool maximize(_Tp &__a, const _Tp &__b) { if (__a < __b) { __a = __b; return true; } return false; }
#define int long long 
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(), a.end()
#define allof(a,n) a + 1, a + 1 + n
#define fo(i,a,b) for(int i = a; i <= b; i++)
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define file ""
#define I ios_base :: sync_with_stdio(0);
#define wish cin.tie(0);
#define have cout.tie(0);
#define tomorrow freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int single_test = 0;
const int base = 31;
int n;
int cost[maxn], par[maxn];
vector<pii> g;
bool cmp(pii a, pii b)
{
    int x = max(cost[a.fi], cost[a.se]), y = max(cost[b.fi],cost[b.se]);
    return x < y;
}
int find(int v)
{
    return v == par[v] ? v : par[v] = find(par[v]);
}
int ans;
void Union(int u, int v)
{
    u = find(u), v = find(v);
    if(u != v)
    {
        ans += cost[u] + cost[v];
        maximize(cost[v], cost[u]);
        par[u] = v;
    }
}
namespace orzac
{
    void solve()
    {
        cin >> n;
        fo(i, 1, n)
        {
            cin >> cost[i];
            par[i] = i;
        }
        fo(i, 1, n - 1)
        {
            int u, v;
            cin >> u >> v;
            g.pb({u, v});
        }
        sort(g.begin(), g.end(), cmp);
        for(auto x : g) 
            Union(x.fi, x.se);
        cout << ans;
    }
}
int32_t main()
{
    I wish have //tomorrow
    int t = 1;
    if(single_test)
        cin >> t;
    while(t--)
        orzac :: solve();
}

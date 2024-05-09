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
const int maxn = 3e6 + 5;
const int mod = 1e9 + 7;
const int single_test = 0;
const int base = 31;
int n, a[maxn], p[maxn], sum[maxn], sz[maxn], par[maxn];
void init(int u)
{
    par[u] = u;
    sz[u] = 1;
    sum[u] = a[u];
}
int find(int v)
{
    return (v == par[v] ? v : par[v] = find(par[v]));
}
void unionset(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    if(sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    sum[u] += sum[v];
}
map<int, int> m;
namespace orzac
{
    void solve()
    {
        cin >> n;
        fo(i, 1, n)
            cin >> a[i];
        fo(i, 1, n)
            cin >> p[i];
        fo(i, 1, n)
            init(i);
        int ans = 0;
        int anss[n + 2] = {};
        for(int i = n; i >= 1; i--)
        {
            m[p[i]] = 1;
            if(p[i] > 1 && m[p[i] - 1])
                unionset(p[i], p[i] - 1);
            if(p[i] < n && m[p[i] + 1]) 
                unionset(p[i], p[i] + 1);
            maximize(ans, sum[find(p[i])]);
            anss[i - 1] = ans;
        }
        fo(i, 1, n)
            cout << anss[i] << "\n";
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

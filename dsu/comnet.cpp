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
const int single_test = 1;
const int base = 31;
struct node
{
    int u, v, costcu, costmoi;
};
int par[maxn], sz[maxn];
int find(int v)
{
    return v == par[v] ? v : par[v] = find(par[v]);
}
void Union(int u, int v)
{
    u = find(u); v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
namespace orzac
{
    void solve()
    {
        int n, m, q;
        cin >> n >> m >> q;
        node a[m + 1];
        fo(i, 1, m)
            cin >> a[i].u >> a[i].v >> a[i].costcu;
        while(q--)
        {
            fo(i, 1, n) par[i] = i, sz[i] = 0;
            int k, thay;
            cin >> k >> thay;
            int xet[thay + 1];
            fo(i, 1, thay)
            {
                int neww, newcost;
                cin >> neww >> newcost;
                a[neww].costmoi = newcost;
                swap(a[neww].costcu, a[neww].costmoi);
                xet[i] = neww;
            }
            fo(i, 1, m)
                if(a[i].costcu < a[k].costcu) Union(a[i].u, a[i].v);
            cout << (find(a[k].u) == find(a[k].v) ? "YES\n" : "NO\n");
            fo(i, 1, thay)
            {
                int neww = xet[i];
                swap(a[neww].costcu, a[neww].costmoi);
            }
        }
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

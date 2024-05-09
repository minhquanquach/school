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
const int maxn = 1e5 + 4;
const int mod = 1e9 + 7;
const int single_test = 0;
const int base = 31;
int par[maxn + 1];
vector<map<int,int>> dp(maxn);
int n, q;
void make_set()
{
    fo(i, 1, maxn)
        par[i] = i;
}
int find_set(int v)
{
    return v == par[v] ? v : par[v] = find_set(par[v]);
}
bool union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b)
        return 0;
    if(dp[a].size() < dp[b].size()) swap(a,b);
    par[b] = a;
    for(auto v : dp[b])
        dp[a][v.fi] += v.se;
    return 1;
}
namespace orzac
{
    void solve()
    {
        cin >> n >> q;
        make_set();
        fo(i, 1, n)
        {
            int x;
            cin >> x;
            dp[i][x] = 1;
        }
        fo(i, 1, q)
        {
            int type, u, v;
            cin >> type >> u >> v;
            if(type & 1)
                union_set(u, v);
            else cout << dp[find_set(u)][v] << "\n";
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

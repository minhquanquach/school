#include <bits/stdc++.h>
using namespace std;
template <typename _Tp> bool minimize(_Tp &__a, const _Tp &__b) { if (__a > __b) { __a = __b; return true; } return false; }
template <typename _Tp> bool maximize(_Tp &__a, const _Tp &__b) { if (__a < __b) { __a = __b; return true; } return false; }
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
struct Trie
{
    struct Node
    {
        Node* child[26];
        set<int> pos;
        Node()
        {
            fo(i, 0, 25) child[i] = nullptr;
        }
    };
    Node* root=new Node();
    void insert(string st,int pos)
    {
        Node* p = root;
        for(auto chr : st)
            {
                if (p -> child[chr - 'a'] == nullptr) p -> child[chr - 'a'] = new Node();
                p = p -> child[chr - 'a'];
            }
        p -> pos.insert(pos);
    }
    void del(string st,int pos)
    {
        Node* p = root;
        for(auto chr : st) p = p -> child[chr - 'a'];
        p -> pos.erase(pos);
    }
    bool vprefix(string st,int l,int r)
    {
        Node* p = root;
        for(auto chr : st)
            {
                if (p -> child[chr - 'a'] == nullptr) return 0;
                p = p -> child[chr - 'a'];
                int pos = *p -> pos.lower_bound(l);
                if (pos >= l && pos <= r) return 1;
            }
        return 0;
    }
    bool dfs(Node* p,int l,int r)
    {
        int pos = *p -> pos.lower_bound(l);
        if (pos >= l && pos <= r) return 1; 
        for(char chr = 'a'; chr <= 'z'; chr++)
            if (p -> child[chr - 'a'] != nullptr) 
                if (dfs(p -> child[chr - 'a'], l, r)) return 1;
        return 0;    
    }
    bool sprefix(string st,int l,int r)
    {
        Node* p = root;
        for(auto chr : st)
            if (p -> child[chr - 'a'] == nullptr) return 0;
            else p = p -> child[chr - 'a'];
        return dfs(p, l, r);
    }
} trie;
namespace orzac
{
    void solve()
    {
        int n;
        cin >> n;
        string a[n + 1];
        fo(i, 1, n)
        {
            cin >> a[i];
            trie.insert(a[i],i);
        }
        int t;
        cin >> t;
        while(t--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int pos;
                string st;
                cin >> pos >> st;
                trie.del(a[pos],pos);
                a[pos] = st;
                trie.insert(a[pos],pos);
            }
            else if(type==2)
            {
                int l,r;
                string st;
                cin >> l >> r >> st;
                cout << (trie.vprefix(st,l,r) ? "Y" : "N") << "\n";
            }
            else 
            {
                int l,r;
                string st;
                cin >> l >> r >> st;
                cout << (trie.sprefix(st,l,r) ? "Y" : "N") << "\n";
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

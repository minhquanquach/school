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
struct Trie{
    struct Node{
        int count, exist;
        Node* child[26];
        Node(){
            count = exist = 0;
            fo(i, 0, 25)
                child[i]=nullptr;
        }
    };
    int res = 0;
    Node*root = new Node();
    void insert(string s)
    {
        Node *p = root;
        for(auto c : s)
        {
            if(p->child[c-'a']==nullptr) p->child[c-'a'] = new Node();
            p = p->child[c-'a'];
            p->count++;
        }
        p->exist++;
    }
    void dfs(Node* p, int cnt){
        res += p->exist * (p->exist - 1) / 2;
        res += p->exist * cnt;
        fo(i, 0, 25)
            if(p->child[i]!=nullptr)
                dfs(p->child[i], cnt+p->exist);
    }
    void calc(){
        dfs(root, 0);
    }
} trie;
namespace orzac
{
    void solve()
    {
        int n;
        cin >> n;
        fo(i, 1, n)
        {
            string s;
            cin >> s;
            trie.insert(s);
        }
        trie.calc();
        cout << trie.res;
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

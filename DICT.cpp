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
struct Trie
{
    struct Node
    {
        Node* child[27];
        bool _end;
        Node()
        { 
            _end=0;
            for(int i=0;i<27;i++) child[i]=nullptr;
        }
    };
    Node* root;
    Trie()
    {
        root=new Node();
    }
    void insert(string st)
    {
        Node* p=root;
        for(auto chr:st)
            {
                if (p->child[chr-'a']==nullptr) p->child[chr-'a']=new Node();
                p=p->child[chr-'a'];
            }
        p->_end=1;
    }
    void dfs(Node* p,string st)
    {
        if (p->_end) cout<<st<<"\n";
        for(char chr='a';chr<='z';chr++)
            if (p->child[chr-'a']!=nullptr) dfs(p->child[chr-'a'],st+chr); 
    }
    void find(string st)
    {
        Node* p=root;
        for(auto chr:st) 
            if (p->child[chr-'a']!=nullptr) p=p->child[chr-'a'];
            else return cout<<"No match.\n",void();
        bool ok=0;
        for(char chr='a';chr<='z';chr++)
            if (p->child[chr-'a']!=nullptr) 
                {
                    ok=1;dfs(p->child[chr-'a'],st+chr);
                }
        if (ok==0) cout<<"No match.\n";
    }
} trie;
namespace orzac
{
    void solve()
    {
        int n;
        cin >> n;
        while (n--)
        {
            string st;
            cin >> st;
            trie.insert(st);
        }
        int m;cin>>m;
        for(int i = 1;i <= m; i++)
        {
            cout << "Case #" << i << ":\n";
            string st;
            cin >> st;
            trie.find(st);
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

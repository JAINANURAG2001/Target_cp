#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}


// finding the maximum distinct elements int the  subarray of size k
// using sliding window technique

void solve()
{   
    int n,k;
    cin>>n>>k ;

    vector<int> v(n);
   for(auto & i : v){
        cin>>i;
    }
    // methid -1

    // int maxi=0;
    // for (int i = 0; i < n-k; i++)
    // {
    //         set<int>s ;

    //         for(int j=i ;j<i+k;j++){
    //             s.insert(v[j]);
    //         }

    //         int ans = s.size();
    //         maxi=max(maxi, ans);
        
    // }
    // cout<<maxi <<endl ;



    // Method -2
    map<int , int > mp ;


    for (int i=0;i<k ;i++){
        mp[v[i]]++ ;
    }

    int ans = mp.size() ;

    for(int i=k ;i<n ;i++){
        mp[v[i]]++ ;
        mp[v[i-k]]-- ;
        if(mp[v[i-k]]==0){
            mp.erase(v[i-k]);
        }
        ans = max(ans , (int)mp.size());
    }

cout<<ans <<endl ;


    // Method -3
    // unordered_map<int , int > mp ;
    // int i=0,j=0, ans = 0 ;

    // while(j<n){
    //     mp[v[j]]++ ;
    //     if(j-i+1 < k){
    //         j++;
    //     }
    //     else if(j-i+1 == k){
    //         ans = max(ans , (int)mp.size());
    //         mp[v[i]]-- ;
    //         if(mp[v[i]]==0){
    //             mp.erase(v[i]);
    //         }
    //         i++;
    //         j++;
    //     }
    // }
    // cout<<ans <<endl ;

}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
// Anurag Jain
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
